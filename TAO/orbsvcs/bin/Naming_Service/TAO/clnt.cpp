// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO/orbsvcs/bin/Naming_Service/TAO
//
// = FILENAME
//    clnt.cpp
//
// = DESCRIPTION
//      This class implements a simple "cube" CORBA client for the CosNaming 
//      example using stubs generated by the TAO ORB IDL compiler.
//
// = AUTHORS
//      Sergio Flores-Gaitan <sergio@cs.wustl.edu>
//
// ============================================================================

#include "clnt.h"
#include "CosNaming_i.h"

// constructor

CosNaming_Client::CosNaming_Client (void)
  : hostname_ ("localhost"),
    portnum_ (TAO_DEFAULT_SERVER_PORT),
    exit_later_ (0),
    factory_ (CORBA::Object::_nil ()),
    objref_ (CORBA::Object::_nil ()),
    CosNaming_ (CosNaming::NamingContext::_nil ()),
    cosnaming_factory_key_ ("naming_context")
{
}

// Parses the command line arguments and returns an error status.

int
CosNaming_Client::parse_args (void)
{
  ACE_Get_Opt get_opts (argc_, argv_, "dn:h:p:k:x");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'd':  // debug flag
	TAO_debug_level++;
	break;
      case 'h':
        hostname_ = ACE_OS::strdup (get_opts.optarg);
        break;
      case 'p':
        portnum_ = ACE_OS::atoi (get_opts.optarg);
        break;
      case 'x':
	this->exit_later_++;
	break;
      case '?':
      default:
	ACE_ERROR_RETURN ((LM_ERROR,
			   "usage:  %s"
			   " [-d]"
                           " [-h hostname]"
                           " [-p port]"
			   " [-x]"
			   "\n",
                           this->argv_ [0]), 
                          -1);
      }

  // Indicates successful parsing of command line.
  return 0;  
}

// Execute client example code.

int
CosNaming_Client::run (void)
{


  if (this->exit_later_)
    {
      //  this->please_exit (this->env_);
      dexc (this->env_, "server, please ACE_OS::exit");
    }

  return 0;
}

CosNaming_Client::~CosNaming_Client (void)
{
  CORBA::release (this->CosNaming_);
  CORBA::release (this->factory_);
}

int
CosNaming_Client::init (int argc, char **argv)
{
  this->argc_ = argc;
  this->argv_ = argv;

  //  CosNaming::NamingContext_ptr cos_naming_i = new CosNaming::NamingContext;

  // retrieve the ORB
  CORBA::ORB_init (this->argc_,
                   this->argv_,
                   "nameserver",
                   this->env_);

  if (this->env_.exception () != 0)
    {
      this->env_.print_exception ("ORB initialization");
      return 1;
    }

  // Parse command line and verify parameters.
  if (this->parse_args () == -1)
    return 1;

  // Retrieve a factory objref.
  this->objref_ = CosNaming::NamingContext::_bind (this->hostname_,
						   this->portnum_,
						   this->cosnaming_factory_key_,
						   this->env_);

  if (this->env_.exception () != 0)
    {
      this->env_.print_exception ("CosNaming_Factory::_bind");
      return 1;
    }

  if (CORBA::is_nil (this->objref_) == CORBA::B_TRUE)
    ACE_ERROR_RETURN ((LM_ERROR,
                       " _bind returned null object for host (%s), port (%d)\n",
                       this->hostname_,
                       this->portnum_),
                      1);

  // Narrow the CORBA::Object reference to the stub object, checking
  // the type along the way using _is_a.  There is really no need to
  // narrow <objref> because <_bind> will return us the
  // <CosNaming_Factory> pointer.  However, we do it so that we can
  // explicitly test the _narrow function.

  this->CosNaming_ = CosNaming::NamingContext::_narrow (this->objref_);

  if (this->CosNaming_ == 0)
    ACE_ERROR_RETURN ((LM_ERROR,
		       " (%P|%t) Unable to narrow object reference to a CosNaming_ptr.\n"),
		      1);

  if (this->env_.exception () != 0)
    {
      this->env_.print_exception ("CosNaming::NamingContext::_narrow");
      return 1;
    }

  if (CORBA::is_nil (this->CosNaming_))
    ACE_ERROR_RETURN ((LM_ERROR,
                       "null CosNaming objref returned by factory\n"),
                      1);

  return 0;
}

// This function runs the test.

int
main (int argc, char **argv)
{
  CosNaming_Client cosnaming_client;
  
  if (cosnaming_client.init (argc, argv) == -1)
    return 1;
  else
    return cosnaming_client.run ();
}
