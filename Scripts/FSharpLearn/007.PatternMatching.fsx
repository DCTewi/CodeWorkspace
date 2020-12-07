type Shape = 
    | Circle of radius: int
    | Rectangle of height: int * width:int 
    | Point of x: int * y: int
    | Polygon of pointList: (int * int) list

let draw shape = 
    match shape with
    | Circle radius ->
        printfn "The circle has a radius of %d" radius
    | Rectangle (h, w) ->
        printfn "The rectangle is %d high by %d wide" h w
    | Polygon ps ->
        printfn "The polygon is made of points %A" ps
    | Point (x, y) ->
        printfn "The point is %A" (x, y)

let circle = Circle 10
let rect = Rectangle (4, 5)
let point = Point (2, 3)
let poly = Polygon [(1, 1); (2, 2); (3, 3)]

[circle; rect; point; poly] |> List.iter draw
