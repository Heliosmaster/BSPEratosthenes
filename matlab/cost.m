function c = cost(n,p,g,l)
q = floor(sqrt(n));
c = q*log(log(q))+(n-q)/p*log(log((n-q)/p))+p+(p-1)*g+3*l;