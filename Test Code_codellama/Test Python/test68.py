def train(category_tensor, line_tensor, rnn, criterion, optimizer):
    hidden = rnn.initHidden()
    for i in range(line_tensor.size()[0]):
        output, hidden = rnn(line_tensor[i], hidden)
        loss = criterion(output, category_tensor[i])
        optimizer.zero_grad()
        loss.backward()
        optimizer.step()