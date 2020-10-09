function []=newton_binomial(P, T) // Probability of just one entry; Times of entries;
    for i=0:P^T-1
        str = dec2base(i, P)
        printf("%0*d\n", T, strtod(str));
    end
endfunction
