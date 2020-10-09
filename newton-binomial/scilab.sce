//INPUT: Function f, endpoint values a, b, tolerance TOL, maximum iterations NMAX
//CONDITIONS: a < b, either f(a) < 0 and f(b) > 0 or f(a) > 0 and f(b) < 0
//OUTPUT: value which differs from a root of f(x)=0 by less than TOL
//// 
//NMAX=500;
//TOL = 10^(6);
//
//a = input('Digite valor inicial A:');
//b = input('Digite valor final B: ');
//
//for N = 1:NMAX // limit iterations to prevent infinite loop
//  c = (a + b)/2 // new midpoint
//  if ((function_R_root(c) == 0) || ( (b-a)/2 < TOL) ) then //# solution found
//    disp('Raiz aproximada é: ',c)
//    exit
//  end
//  N = N + 1 //# increment step counter
//  If sign(f(c)) = sign(function_R_root(a)) then a = c else b = c //# new interval
//end
//disp("Method failed.") // max number of steps exceeded
exec("/home/mateus/ban/math/scilab/function-with Real root.sce")
NMAX=500;
TOL = 10^6;
a=input('Digite valor inicial A: ');
b=input('Digite valor inicial B: ');
for N = 1:NMAX
    c=(a+b)/2;
    w = (function_R_root(c) == 0);
    q = (( (b-a)/2) < TOL );
    if( w | q ) then
        disp('Raiz aprox: ',c)
        break;
    end    
    if ( sign(function_R_root(c)) == sign(function_R_root(a)) ) then a=c; else b=c; end
end
disp("Method failed failed failure BSOD BSDO KP KP KP BSOD")
