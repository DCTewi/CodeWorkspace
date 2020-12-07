let square x = x * x

let sumOfSquares n = 
    [1.0..n] 
    |> List.sumBy square

sumOfSquares 100.0

