function [J grad] = nnCostFunction(nn_params, ...
                                   input_layer_size, ...
                                   hidden_layer_size, ...
                                   num_labels, ...
                                   X, y, lambda)
%NNCOSTFUNCTION Implements the neural network cost function for a two layer
%neural network which performs classification
%   [J grad] = NNCOSTFUNCTON(nn_params, hidden_layer_size, num_labels, ...
%   X, y, lambda) computes the cost and gradient of the neural network. The
%   parameters for the neural network are "unrolled" into the vector
%   nn_params and need to be converted back into the weight matrices. 
% 
%   The returned parameter grad should be a "unrolled" vector of the
%   partial derivatives of the neural network.
%

% Reshape nn_params back into the parameters Theta1 and Theta2, the weight matrices
% for our 2 layer neural network
Theta1 = reshape(nn_params(1:hidden_layer_size * (input_layer_size + 1)), ...
                 hidden_layer_size, (input_layer_size + 1));

Theta2 = reshape(nn_params((1 + (hidden_layer_size * (input_layer_size + 1))):end), ...
                 num_labels, (hidden_layer_size + 1));

% Setup some useful variables
m = size(X, 1);
         
% You need to return the following variables correctly 
J = 0;
Theta1_grad = zeros(size(Theta1));
Theta2_grad = zeros(size(Theta2));

% ====================== YOUR CODE HERE ======================
% Instructions: You should complete the code by working through the
%               following parts.
%
% Part 1: Feedforward the neural network and return the cost in the
%         variable J. After implementing Part 1, you can verify that your
%         cost function computation is correct by verifying the cost
%         computed in ex4.m
%
%正向传播计算激活项
X = [ones(m, 1) X];%X变为5000x401 a1
temp = sigmoid(X * Theta1');%temp为5000x25
temp = [ones(m, 1) temp];%temp变为5000x26
h = sigmoid(temp * Theta2');%h为5000x10
temp_y = zeros(size(h));%temp_y为5000x10的零矩阵
for i = 1:m
    temp_y(i, y(i)) = 1; %完成label的one-hot编码
end
J = (1 / m) * sum(sum(-temp_y .* log(h) - (1 - temp_y) .* log(1 - h))); %计算非正则化的部分
%计算正则化的部分（不正则化偏置对应的那一项，即矩阵的第一列）
Theta1_temp = Theta1(:, 2:end);%Theta1_temp为25x400
Theta2_temp = Theta2(:, 2:end);%Theta2_temp为10x25
J = J + (lambda / 2 / m) * (sum(sum(Theta1_temp .* Theta1_temp)) + sum(sum(Theta2_temp .* Theta2_temp)));
% Part 2: Implement the backpropagation algorithm to compute the gradients
%         Theta1_grad and Theta2_grad. You should return the partial derivatives of
%         the cost function with respect to Theta1 and Theta2 in Theta1_grad and
%         Theta2_grad, respectively. After implementing Part 2, you can check
%         that your implementation is correct by running checkNNGradients
%
%         Note: The vector y passed into the function is a vector of labels
%               containing values from 1..K. You need to map this vector into a 
%               binary vector of 1's and 0's to be used with the neural network
%               cost function.
%
%         Hint: We recommend implementing backpropagation using a for-loop
%               over the training examples if you are implementing it for the 
%               first time.
%
%反向传播计算误差项
delta_3 = h - temp_y; 
delta_2 = delta_3 * Theta2 .* sigmoidGradient([ones(m, 1) X * Theta1']);
delta_2 = delta_2(:, 2:end);
D2 = delta_3' * temp;
D1 = delta_2' * X;
Theta2_grad = 1/m * D2;
Theta1_grad = 1/m * D1;
% Part 3: Implement regularization with the cost function and gradients.
%
%         Hint: You can implement this around the code for
%               backpropagation. That is, you can compute the gradients for
%               the regularization separately and then add them to Theta1_grad
%               and Theta2_grad from Part 2.
%

%Part3：正则化神经网络的梯度
Theta1_temp = Theta1;
Theta1_temp(:, 1) = 0;
Theta2_temp = Theta2;
Theta2_temp(:, 1) = 0;
Theta1_grad = Theta1_grad + lambda / m * Theta1_temp; %j=1的时候lambda / m * Theta1_temp为0，Theta1_grad = Theta1_grad；
                                                      %j不等于1的时候，Theta1_grad = Theta1_grad + lambda / m * Theta1_temp;
Theta2_grad = Theta2_grad + lambda / m * Theta2_temp;














% -------------------------------------------------------------

% =========================================================================

% Unroll gradients
grad = [Theta1_grad(:) ; Theta2_grad(:)];


end
