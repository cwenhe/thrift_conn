#include "MessageService.h"

#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>

#include <memory>

#include <iostream>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

int main()
{

    auto socket = std::make_shared<TSocket>("localhost", 9090);
    std::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
    std::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
    transport->open();


    MessageServiceClient client(protocol);
    Message msg;
    client.latestMessage(msg);

    std::cout<<msg.id<<"---"<<msg.content<<"\n";




    return 0;
}
