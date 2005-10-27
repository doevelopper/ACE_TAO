// -*- C++ -*-

//=============================================================================
/**
 * $Id$
 */
//=============================================================================

#ifndef TAO249_SERVER_REQUEST_INTERCEPTOR_H
#define TAO249_SERVER_REQUEST_INTERCEPTOR_H

#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "tao/LocalObject.h"
#include "tao/PortableInterceptorC.h"
#include "tao/ORB.h"
#include "tao/PI/PI.h"
#include "tao/PI_Server/PI_Server.h"

/**
* $Id$
*/
class TAO249_ServerRequest_Interceptor
: public virtual PortableInterceptor::ServerRequestInterceptor,
  public virtual TAO_Local_RefCounted_Object
{
public:

/// Constructor.
TAO249_ServerRequest_Interceptor (void);

/// Destructor.
~TAO249_ServerRequest_Interceptor (void);

/**
 * @name Methods Required by the Server Request Interceptor
 * Interface
 *
 * These are methods that must be implemented since they are pure
 * virtual in the abstract base class.  They are the canonical
 * methods required for all server request interceptors.
 */
//@{
/// Return the name of this ServerRequestinterceptor.
virtual char * name (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException));

virtual void destroy (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException));

virtual void receive_request_service_contexts (
  PortableInterceptor::ServerRequestInfo_ptr ri
  ACE_ENV_ARG_DECL)
ACE_THROW_SPEC ((CORBA::SystemException,
                 PortableInterceptor::ForwardRequest));

virtual void receive_request (
    PortableInterceptor::ServerRequestInfo_ptr ri
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableInterceptor::ForwardRequest));

virtual void send_reply (
    PortableInterceptor::ServerRequestInfo_ptr ri
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException));

virtual void send_exception (
    PortableInterceptor::ServerRequestInfo_ptr ri
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableInterceptor::ForwardRequest));

virtual void send_other (
    PortableInterceptor::ServerRequestInfo_ptr ri
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableInterceptor::ForwardRequest));
//@}
private:

CORBA::ORB_var orb_;
    
CORBA:: Long client_id_;
};

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#endif  /* TAO249_SERVER_REQUEST_INTERCEPTOR_H */
