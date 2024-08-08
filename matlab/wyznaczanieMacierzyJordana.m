clc, clear;

% Pobierz dane od użytkownika
n = input('Podaj rozmiar macierzy kwadratowej: ');
A = zeros(n);
for i = 1:n
    for j = 1:n
        fprintf('Podaj element (%d,%d): ', i, j);
        A(i,j) = input('');
    end
end
P = zeros(n);
for i = 1:n
    for j = 1:n
        fprintf('Podaj element macierzy przejścia (%d,%d): ', i, j);
        P(i,j) = input('');
    end
end

% Oblicz macierz Jordana
J = P^(-1)*A*P;

% Wyświetl wynik
fprintf('Macierz Jordana:\n');
disp(J);
