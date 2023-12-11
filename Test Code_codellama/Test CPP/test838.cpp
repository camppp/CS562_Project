#include <grpcpp/grpcpp.h>

using grpc::ServerContext;
using grpc::Status;
using grpc::ServerWriter;
using grpc::ClientReader;
using grpc::ClientWriter;

class TestServiceImpl final : public TestService::Service {
 public:
  Status TestUnaryRpc(ServerContext* context, const TestRequest* request, TestResponse* response) override {
    // Implement the logic for the TestUnaryRpc method here
    called_async_unary_method = true;
    return Status::OK;
  }

  Status TestServerStreamRpc(ServerContext* context, const TestRequest* request, ServerWriter<TestResponse>* writer) override {
    // Implement the logic for the TestServerStreamRpc method here
    called_server_streaming_method = true;
    return Status::OK;
  }

  Status TestClientStreamRpc(ServerContext* context, ClientReader<TestRequest>* reader, TestResponse* response) override {
    // Implement the logic for the TestClientStreamRpc method here
    called_client_streaming_method = true;
    return Status::OK;
  }

  Status TestBidirectionalStreamRpc(ServerContext* context, ClientReader<TestRequest>* reader, ServerWriter<TestResponse>* writer) override {
    // Implement the logic for the TestBidirectionalStreamRpc method here
    called_bidirectional_streaming_method = true;
    return Status::OK;
  }
};
