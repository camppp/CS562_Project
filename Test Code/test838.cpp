void TestUnaryRpc(const test::TestRequest::Message& request, test::TestResponse::Message& response) {
    // Implement the logic for the TestUnaryRpc method here
    called_async_unary_method = true;
    // Your implementation logic here
}

void TestServerStreamRpc(ConstByteSpan request, RawServerWriter& writer) {
    // Implement the logic for the TestServerStreamRpc method here
    called_server_streaming_method = true;
    // Your implementation logic here
}

void TestClientStreamRpc(ServerReader<test::TestRequest::Message, test::TestStreamResponse::Message>& reader) {
    // Implement the logic for the TestClientStreamRpc method here
    called_client_streaming_method = true;
    // Your implementation logic here
}

void TestBidirectionalStreamRpc(RawServerReaderWriter& reader_writer) {
    // Implement the logic for the TestBidirectionalStreamRpc method here
    called_bidirectional_streaming_method = true;
    // Your implementation logic here
}
