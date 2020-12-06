module Traditional = 
    open System
    
    let usertimerWithCallback = 
        let event = new Threading.AutoResetEvent false
        let timer = new Timers.Timer 2000.0
        timer.Elapsed.Add (fun _ -> () |> event.Set |> ignore)
    
        printfn "Waiting for timer at %O" DateTime.Now.TimeOfDay
        () |> timer.Start
    
        printfn "Doing something useful while waiting for event"
    
        () |> event.WaitOne |> ignore
    
        printfn "Timer ticked at %O" DateTime.Now.TimeOfDay
    
    usertimerWithCallback

let userTimerWithAsync = 
    let timer = new System.Timers.Timer 2000.0
    let timerEvent = timer.Elapsed |> Async.AwaitEvent |> Async.Ignore

    printfn "Waiting for timer at %O" System.DateTime.Now.TimeOfDay
    () |> timer.Start

    printfn "Doing something"

    Async.RunSynchronously timerEvent

    printfn "Timer ticked at %O" System.DateTime.Now.TimeOfDay

let fileWriteWithAsync =
    use stream = new System.IO.FileStream ("text.txt", System.IO.FileMode.Create)

    printfn "Starting async write"
    let asyncResult = stream.BeginWrite (Array.empty, 0, 0, null, null)
    let async = Async.AwaitIAsyncResult asyncResult |> Async.Ignore

    printfn "Doing something useful"

    Async.RunSynchronously async

    printfn "Async write completed"

open System

let sleepWorkflow = 
    async {
        printfn "Starting sleep workflow at %O" DateTime.Now.TimeOfDay

        do! Async.Sleep 2000
        printfn "Finished at %O" DateTime.Now.TimeOfDay
    }

Async.RunSynchronously sleepWorkflow

let nestedWorkflow = 
    async {
        printfn "Starting parent"
        let! childWorkflow = Async.StartChild sleepWorkflow

        do! Async.Sleep 100
        printfn "Doing something"

        let! result = childWorkflow

        printfn "Finished parent"
    }
Async.RunSynchronously nestedWorkflow

let testLoop = 
    async {
        for i in [1..100] do
            printf "%i before.." i

            do! Async.Sleep 10
            printfn "..after"
    }
Async.RunSynchronously testLoop

open System
open System.Threading

let cancelThread = 
    use cancellationSource = new CancellationTokenSource ()
    
    Async.Start (testLoop, cancellationSource.Token)
    
    Thread.Sleep 200
    
    cancellationSource.Cancel ()

let sleepWorkflowMs ms = 
    async {
        printfn "%i ms workflow started" ms
        do! Async.Sleep ms
        printfn "%i ms workflow finished" ms
    }

let workflowInSeries = 
    async {
        let! sleep1 = sleepWorkflowMs 1000 in
        printfn "Finished one"

        let! sleep2 = sleepWorkflowMs 2000 in
        printfn "Finished two"
    }
#time
Async.RunSynchronously workflowInSeries
#time

let sleep1 = sleepWorkflowMs 1000
let sleep2 = sleepWorkflowMs 2000

#time
// run in parallel
[sleep1; sleep2]
    |> Async.Parallel
    |> Async.RunSynchronously
printfn "Hello!"
#time
