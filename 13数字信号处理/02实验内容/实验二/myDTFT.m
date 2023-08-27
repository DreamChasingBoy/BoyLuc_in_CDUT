function X = myDTFT(x, w)
    N = length(x);
    X = zeros(size(w)); 
    for k = 1:length(w)
        for n = 1:N
            X(k) = X(k) + x(n)*exp(-1i*w(k)*(n-1)); 
        end
    end
end