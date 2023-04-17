using System;

class Program
{
    static int Fibonacci(int n)
    {
        // Caso base: si n es 0, retornamos 0
        if (n == 0)
        {
            return 0;
        }
        // Caso base: si n es 1 o 2, retornamos 1
        else if (n == 1 || n == 2)
        {
            return 1;
        }
        // Si n es mayor que 2, llamamos a la función Fibonacci recursivamente
        else
        {
            return Fibonacci(n - 1) + Fibonacci(n - 2);
        }
    }

    static void Main(string[] args)
    {
        int n = 45;
        Console.WriteLine($"Fibonacci de {n}: {Fibonacci(n)}");
    }
}