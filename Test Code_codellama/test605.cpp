void updateSentMessages(const std::string& reply, int msgs, ClientConnection& fdref, Server* serv) {
    if (reply.find_last_of(CRLF) != reply.length() - 1) {
        msgs--;
    }
    fdref.sentmsgs += msgs;
    if (fdref.sock > 0) {
        serv->fds[fdref.sock].sentmsgs += msgs;
    }
}
