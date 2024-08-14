%basic assignments rev
a = 5
b = 7
a + b
%cond rev
if b > a
    c = b - a
end
%loop rev
for i = 1:5
    disp(i)
end
%case rev
switch c
    case 1
        disp(1)
    case 2
        disp(2)
    case 3
        disp(3)
    otherwise
        disp("err")
end
