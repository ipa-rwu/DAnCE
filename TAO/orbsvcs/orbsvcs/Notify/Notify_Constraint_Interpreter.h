/* -*- C++ -*- */
// $Id$
// ==========================================================================
//
// = LIBRARY
//   orbsvcs
//
// = FILENAME
//   Notify_Constraint_Interpreter.h
//
// = DESCRIPTION
//
//
// = AUTHOR
//    Pradeep Gore <pradeep@cs.wustl.edu>
//
// ==========================================================================

#ifndef TAO_NOTIFY_CONSTRAINT_INTERPRETER_H
#define TAO_NOTIFY_CONSTRAINT_INTERPRETER_H

#include "orbsvcs/orbsvcs/Trader/Constraint_Nodes.h"
#include "orbsvcs/orbsvcs/Trader/Constraint_Visitors.h"
#include "orbsvcs/orbsvcs/Trader/Interpreter.h"
#include "orbsvcs/orbsvcs/CosNotifyFilterS.h"

class TAO_Constraint_Evaluator;

class TAO_ORBSVCS_Export TAO_Notify_Constraint_Interpreter : public TAO_Interpreter
{
  //
  // = TITLE
  //   TAO_Notify_Constraint_Interpreter
  //
  // = DESCRIPTION
  //   "TCL" Interpreter for the Notify queries.
public:
  // = Initialization and termination methods.
  TAO_Notify_Constraint_Interpreter (void);

  ~TAO_Notify_Constraint_Interpreter (void);
  // Destructor

  void build_tree (const char* constraints,
                   CORBA::Environment& ACE_TRY_ENV)
    ACE_THROW_SPEC ((CosNotifyFilter::InvalidConstraint,
                     CORBA::NO_MEMORY));
  // This constructor builds an expression tree representing the
  // constraint specified in <constraints>, and throws an Illegal
  // Constraint exception if the constraint given has syntax errors or
  // semantic errors, such as mismatched types.

  CORBA::Boolean evaluate (TAO_Constraint_Evaluator& evaluator);
  // Returns true if the constraint is evaluated successfully by
  // the evaluator.
};
#endif /* TAO_NOTIFY_CONSTRAINT_INTERPRETER_H */
