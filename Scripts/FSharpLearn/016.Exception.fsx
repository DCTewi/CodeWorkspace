type Result<'a, 'b> = 
    | Success of 'a
    | Failure of 'b

type FileErrorReason = 
    | FileNotFound of string
    | UnauthorizedAccess of string * System.Exception

let performActionOnFile action filePath = 
    try
        use sr = new System.IO.StreamReader (filePath: string)
        let result = action sr
        Success result
    with
        | :? System.IO.FileNotFoundException
            -> FileNotFound filePath |> Failure 
        | :? System.Security.SecurityException as e
            -> UnauthorizedAccess (filePath, e) |> Failure

let middleLayerDo action filePath = 
    let fileResult = performActionOnFile action filePath
    // do some stuff
    fileResult

let topLayerDo action filePath = 
    let fileResult = middleLayerDo action filePath
    // do some stuff
    fileResult

let printFirstLineOfFile filePath = 
    let fileResult = topLayerDo (fun fs->fs.ReadLine()) filePath

    match fileResult with
    | Success result -> 
        printfn "first line is: '%s'" result   
    | Failure reason -> 
       match reason with 
       | FileNotFound file -> 
           printfn "File not found: %s" file
       | UnauthorizedAccess (file, _) -> 
           printfn "You do not have access to the file: %s" file