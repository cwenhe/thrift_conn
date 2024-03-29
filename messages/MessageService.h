/**
 * Autogenerated by Thrift Compiler (0.13.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef MessageService_H
#define MessageService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "message_types.h"



#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class MessageServiceIf {
 public:
  virtual ~MessageServiceIf() {}
  virtual void latestMessage(Message& _return) = 0;
};

class MessageServiceIfFactory {
 public:
  typedef MessageServiceIf Handler;

  virtual ~MessageServiceIfFactory() {}

  virtual MessageServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(MessageServiceIf* /* handler */) = 0;
};

class MessageServiceIfSingletonFactory : virtual public MessageServiceIfFactory {
 public:
  MessageServiceIfSingletonFactory(const ::std::shared_ptr<MessageServiceIf>& iface) : iface_(iface) {}
  virtual ~MessageServiceIfSingletonFactory() {}

  virtual MessageServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(MessageServiceIf* /* handler */) {}

 protected:
  ::std::shared_ptr<MessageServiceIf> iface_;
};

class MessageServiceNull : virtual public MessageServiceIf {
 public:
  virtual ~MessageServiceNull() {}
  void latestMessage(Message& /* _return */) {
    return;
  }
};


class MessageService_latestMessage_args {
 public:

  MessageService_latestMessage_args(const MessageService_latestMessage_args&);
  MessageService_latestMessage_args& operator=(const MessageService_latestMessage_args&);
  MessageService_latestMessage_args() {
  }

  virtual ~MessageService_latestMessage_args() noexcept;

  bool operator == (const MessageService_latestMessage_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const MessageService_latestMessage_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MessageService_latestMessage_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class MessageService_latestMessage_pargs {
 public:


  virtual ~MessageService_latestMessage_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _MessageService_latestMessage_result__isset {
  _MessageService_latestMessage_result__isset() : success(false) {}
  bool success :1;
} _MessageService_latestMessage_result__isset;

class MessageService_latestMessage_result {
 public:

  MessageService_latestMessage_result(const MessageService_latestMessage_result&);
  MessageService_latestMessage_result& operator=(const MessageService_latestMessage_result&);
  MessageService_latestMessage_result() {
  }

  virtual ~MessageService_latestMessage_result() noexcept;
  Message success;

  _MessageService_latestMessage_result__isset __isset;

  void __set_success(const Message& val);

  bool operator == (const MessageService_latestMessage_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const MessageService_latestMessage_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MessageService_latestMessage_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _MessageService_latestMessage_presult__isset {
  _MessageService_latestMessage_presult__isset() : success(false) {}
  bool success :1;
} _MessageService_latestMessage_presult__isset;

class MessageService_latestMessage_presult {
 public:


  virtual ~MessageService_latestMessage_presult() noexcept;
  Message* success;

  _MessageService_latestMessage_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class MessageServiceClient : virtual public MessageServiceIf {
 public:
  MessageServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  MessageServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void latestMessage(Message& _return);
  void send_latestMessage();
  void recv_latestMessage(Message& _return);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class MessageServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<MessageServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (MessageServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_latestMessage(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  MessageServiceProcessor(::std::shared_ptr<MessageServiceIf> iface) :
    iface_(iface) {
    processMap_["latestMessage"] = &MessageServiceProcessor::process_latestMessage;
  }

  virtual ~MessageServiceProcessor() {}
};

class MessageServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  MessageServiceProcessorFactory(const ::std::shared_ptr< MessageServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::std::shared_ptr< MessageServiceIfFactory > handlerFactory_;
};

class MessageServiceMultiface : virtual public MessageServiceIf {
 public:
  MessageServiceMultiface(std::vector<std::shared_ptr<MessageServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~MessageServiceMultiface() {}
 protected:
  std::vector<std::shared_ptr<MessageServiceIf> > ifaces_;
  MessageServiceMultiface() {}
  void add(::std::shared_ptr<MessageServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void latestMessage(Message& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->latestMessage(_return);
    }
    ifaces_[i]->latestMessage(_return);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class MessageServiceConcurrentClient : virtual public MessageServiceIf {
 public:
  MessageServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  MessageServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void latestMessage(Message& _return);
  int32_t send_latestMessage();
  void recv_latestMessage(Message& _return, const int32_t seqid);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif



#endif
