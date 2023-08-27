function idx = findClosestCentroids(X, centroids)
%FINDCLOSESTCENTROIDS computes the centroid memberships for every example
%   idx = FINDCLOSESTCENTROIDS (X, centroids) returns the closest centroids
%   in idx for a dataset X where each row is a single example. idx = m x 1 
%   vector of centroid assignments (i.e. each entry in range [1..K])
%

% Set K
K = size(centroids, 1);

% You need to return the following variables correctly.
idx = zeros(size(X,1), 1);
m=zeros(size(idx,1),3);
% ====================== YOUR CODE HERE ======================
% Instructions: Go over every example, find its closest centroid, and store
%               the index inside idx at the appropriate location.
%               Concretely, idx(i) should contain the index of the centroid
%               closest to example i. Hence, it should be a value in the 
%               range 1..K
%
% Note: You can use a for-loop over the examples to compute this.
%
% for i=1:size(idx)
%    m(i,1)=norm(X(i,:)- centroids(1,:));
%    m(i,2)=norm(X(i,:)- centroids(2,:));
%    m(i,3)=norm(X(i,:)- centroids(3,:));
% end
% for j=1:size(idx)
%     idx(j)=min(m(j,:));
%     if(idx(j)==m(j,1))
%         idx(j)=1;
%     end
%     if(idx(j)==m(j,2))
%         idx(j)=2;
%     end
%     if(idx(j)==m(j,3))
%         idx(j)=3;
%     end
% end
for i = 1:size(X,1)
  dist = pdist([X(i,:);centroids]);%D=pdist(x) 计算m*n的数据矩阵中对象之间的欧几里得距离
  dist =dist(:,1:K);%得到每一个样本到所有聚类中心的距离
  [row, col] = find(dist == min(dist));
  idx(i) = col(1);
end


% =============================================================

end

