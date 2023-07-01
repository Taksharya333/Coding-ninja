void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
    int temp;
    while (!input.empty()) {
        temp=input.top();
        input.pop();
      extra.push(temp);
    }
    stack<int> another;
    while (!extra.empty()) {
        temp=extra.top();
        extra.pop();
      another.push(temp);
    }
    while (!another.empty()) {
        temp=another.top();
        another.pop();
      input.push(temp);
    }
}