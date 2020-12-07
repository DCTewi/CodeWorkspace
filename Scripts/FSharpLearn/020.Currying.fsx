let printTwoParametersCurrying x y =
    printfn "x=%i y=%i" x y

let printTwoParametersFunc x =
    let subFunc y =
        printfn "x=%i y=%i" x y
    subFunc

let printTwoParameters x = 
    fun y -> printfn "x=%i y=%i" x y

printTwoParameters 2 3

printTwoParametersFunc 2 3

printTwoParametersCurrying 2 3


let addXYCurrying x y =
    x + y

let addXYFunc x =
    let subFunc y =
        (+) x y
    subFunc

let addXY x = 
    fun y -> x + y

addXY 1 2

addXYFunc 1 2

addXYCurrying 1 2

// baked in
let intermediateFn = (+) 2

intermediateFn 5

let multiParamFn (p1:int)(p2:bool)(p3:string)(p4:float) = () 

let intermediateFn1 = multiParamFn 42    
let intermediateFn2 = intermediateFn1 false    
let intermediateFn3 = intermediateFn2 "hello"  
let finalResult = intermediateFn3 3.141

let printHelloFunc () = printfn "helloFunc"
let printHello = printfn "hello"

printHelloFunc
printHello
