// $Id$

#include "tao/Messaging_Policy_i.h"

#if defined (TAO_HAS_CORBA_MESSAGING)

#if ! defined (__ACE_INLINE__)
#include "tao/Messaging_Policy_i.i"
#endif /* __ACE_INLINE__ */

ACE_RCSID(TAO, Messaging_Policy_i, "$Id$")

TAO_RelativeRoundtripTimeoutPolicy_i::TAO_RelativeRoundtripTimeoutPolicy_i (
    PortableServer::POA_ptr poa,
    const TimeBase::TimeT& relative_expiry)
  :  poa_ (PortableServer::POA::_duplicate (poa)),
     relative_expiry_ (relative_expiry)
{
}

TAO_RelativeRoundtripTimeoutPolicy_i::TAO_RelativeRoundtripTimeoutPolicy_i (const TAO_RelativeRoundtripTimeoutPolicy_i &rhs)
  : TAO_RefCountServantBase (rhs),
    POA_Messaging::RelativeRoundtripTimeoutPolicy (rhs),
    poa_ (rhs.poa_),
    relative_expiry_ (rhs.relative_expiry_)
{
}

TimeBase::TimeT
TAO_RelativeRoundtripTimeoutPolicy_i::relative_expiry (
      CORBA::Environment &
    )
{
  return this->relative_expiry_;
}

CORBA::PolicyType
TAO_RelativeRoundtripTimeoutPolicy_i::policy_type (
      CORBA_Environment &
    )
{
  // Future policy implementors: notice how this minimizes the
  // footprint of the class.
  return TAO_MESSAGING_RELATIVE_RT_TIMEOUT_POLICY_TYPE;
}

CORBA::Policy_ptr
TAO_RelativeRoundtripTimeoutPolicy_i::create (
      PortableServer::POA_ptr poa,
      const CORBA::Any& val,
      CORBA::Environment &ACE_TRY_ENV
    )
{
  // Future policy implementors: notice how the following code is
  // exception safe!

  TimeBase::TimeT value;
  if ((val >>= value) == 0)
    ACE_THROW_RETURN (CORBA::PolicyError (CORBA::BAD_POLICY_TYPE),
                      CORBA::Policy::_nil ());

  TAO_RelativeRoundtripTimeoutPolicy_i *tmp;
  ACE_NEW_THROW_EX (tmp,
                    TAO_RelativeRoundtripTimeoutPolicy_i (poa,
                                                        value),
                    CORBA::NO_MEMORY (TAO_DEFAULT_MINOR_CODE,
                                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (CORBA::Policy::_nil ());

  PortableServer::ServantBase_var clone (tmp);

  CORBA::Policy_var result = tmp->_this (ACE_TRY_ENV);
  ACE_CHECK_RETURN (CORBA::Policy::_nil ());

  return result._retn ();
}

TAO_RelativeRoundtripTimeoutPolicy_i *
TAO_RelativeRoundtripTimeoutPolicy_i::clone (void) const
{
  TAO_RelativeRoundtripTimeoutPolicy_i *copy = 0;
  ACE_NEW_RETURN (copy,
                  TAO_RelativeRoundtripTimeoutPolicy_i (*this),
                  0);
  return copy;
}

CORBA::Policy_ptr
TAO_RelativeRoundtripTimeoutPolicy_i::copy (
      CORBA_Environment &ACE_TRY_ENV
    )
{
  // Future policy implementors: notice how the following code is
  // exception safe!

  TAO_RelativeRoundtripTimeoutPolicy_i* tmp;
  ACE_NEW_THROW_EX (tmp, TAO_RelativeRoundtripTimeoutPolicy_i (*this),
                    CORBA::NO_MEMORY (TAO_DEFAULT_MINOR_CODE,
                                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (CORBA::Policy::_nil ());

  PortableServer::ServantBase_var clone (tmp);

  CORBA::Policy_var result = tmp->_this (ACE_TRY_ENV);
  ACE_CHECK_RETURN (CORBA::Policy::_nil ());

  return result._retn ();
}

void
TAO_RelativeRoundtripTimeoutPolicy_i::destroy (
      CORBA_Environment &ACE_TRY_ENV
    )
{
  PortableServer::ObjectId_var id =
    this->poa_->servant_to_id (this, ACE_TRY_ENV);
  ACE_CHECK;
  this->poa_->deactivate_object (id.in (), ACE_TRY_ENV);
  ACE_CHECK;
}

PortableServer::POA_ptr
TAO_RelativeRoundtripTimeoutPolicy_i::_default_POA (
      CORBA_Environment &
    )
{
  return PortableServer::POA::_duplicate (this->poa_.in ());
}

////////////////////////////////////////////////////////////////////////////////

TAO_Sync_Scope_Policy::TAO_Sync_Scope_Policy (Messaging::SyncScope synchronization,
                                              PortableServer::POA_ptr poa)
  : synchronization_ (synchronization),
    poa_ (PortableServer::POA::_duplicate (poa))
{
}

TAO_Sync_Scope_Policy::TAO_Sync_Scope_Policy (const TAO_Sync_Scope_Policy &rhs)
  : TAO_RefCountServantBase (rhs),
    POA_Messaging::SyncScopePolicy (rhs),
    synchronization_ (rhs.synchronization_),
    poa_ (rhs.poa_)
{
}

Messaging::SyncScope
TAO_Sync_Scope_Policy::synchronization (CORBA::Environment &)
{
  return this->synchronization_;
}

Messaging::SyncScope
TAO_Sync_Scope_Policy::synchronization (void)
{
  return this->synchronization_;
}

CORBA::PolicyType
TAO_Sync_Scope_Policy::policy_type (CORBA_Environment &)
{
  return Messaging::SYNC_SCOPE_POLICY_TYPE;
}

CORBA::Policy_ptr
TAO_Sync_Scope_Policy::create (PortableServer::POA_ptr poa,
                               const CORBA::Any& val,
                               CORBA::Environment &ACE_TRY_ENV)
{
  Messaging::SyncScope synchronization;
  if ((val >>= synchronization) == 0)
    ACE_THROW_RETURN (CORBA::PolicyError (CORBA::BAD_POLICY_TYPE),
                      CORBA::Policy::_nil ());

  TAO_Sync_Scope_Policy *servant = 0;
  ACE_NEW_THROW_EX (servant,
                    TAO_Sync_Scope_Policy (synchronization,
                                           poa),
                    CORBA::NO_MEMORY ());
  ACE_CHECK_RETURN (CORBA::Policy::_nil ());

  PortableServer::ServantBase_var smart_servant (servant);

  CORBA::Policy_var result = servant->_this (ACE_TRY_ENV);
  ACE_CHECK_RETURN (CORBA::Policy::_nil ());

  return result._retn ();
}

TAO_Sync_Scope_Policy *
TAO_Sync_Scope_Policy::clone (void) const
{
  TAO_Sync_Scope_Policy *copy = 0;
  ACE_NEW_RETURN (copy,
                  TAO_Sync_Scope_Policy (*this),
                  0);
  return copy;
}

CORBA::Policy_ptr
TAO_Sync_Scope_Policy::copy (CORBA_Environment &ACE_TRY_ENV)
{
  TAO_Sync_Scope_Policy *servant = 0;
  ACE_NEW_THROW_EX (servant,
                    TAO_Sync_Scope_Policy (*this),
                    CORBA::NO_MEMORY ());
  ACE_CHECK_RETURN (CORBA::Policy::_nil ());

  PortableServer::ServantBase_var smart_servant (servant);

  CORBA::Policy_var result = servant->_this (ACE_TRY_ENV);
  ACE_CHECK_RETURN (CORBA::Policy::_nil ());

  return result._retn ();
}

void
TAO_Sync_Scope_Policy::destroy (CORBA_Environment &ACE_TRY_ENV)
{
  PortableServer::ObjectId_var id =
    this->poa_->servant_to_id (this,
                               ACE_TRY_ENV);
  ACE_CHECK;

  this->poa_->deactivate_object (id.in (),
                                 ACE_TRY_ENV);
  ACE_CHECK;
}

PortableServer::POA_ptr
TAO_Sync_Scope_Policy::_default_POA (CORBA_Environment &)
{
  return PortableServer::POA::_duplicate (this->poa_.in ());
}

////////////////////////////////////////////////////////////////////////////////

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

#elif defined(ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

#endif /* TAO_HAS_CORBA_MESSAGING */
