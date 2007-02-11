#include "tao/Utils/PolicyList_Destroyer.h"

#if !defined (__ACE_INLINE__)
# include "tao/Utils/PolicyList_Destroyer.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID (Utils,
           PolicyList_Deactivator,
           "$Id$")

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO::Utils::PolicyList_Destroyer::~PolicyList_Destroyer()
{

  for (CORBA::ULong i = 0; i != length(); ++i)
    {
      CORBA::Policy_ptr policy = (*this)[i];
      if (CORBA::is_nil (policy))
        {
          continue;
        }

      try
        {
          policy->destroy ();
        }
      catch (...)
        {
        }

      (*this)[i] = CORBA::Policy::_nil();
    }
}

TAO_END_VERSIONED_NAMESPACE_DECL
