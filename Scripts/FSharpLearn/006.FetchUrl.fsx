open System
open System.Net
open System.IO

let fetchUrl callback url =
    let req = url 
              |> Uri
              |> WebRequest.Create
    use resp = req.GetResponse ()
    use stream = resp.GetResponseStream ()
    use reader = new StreamReader (stream)
    callback reader url

let myCallback (reader: StreamReader) url =
    let html = reader.ReadToEnd ()
    let html1000 = html.Substring (0, 1000)
    printfn "Downloaded %s. First 1000 is %s" url html1000
    html

fetchUrl myCallback "https://www.baidu.com"


let fetchUrl2 = fetchUrl myCallback

let sites = 
    [
        "https://www.baidu.com"
        "https://www.bing.com"
    ]
sites |> List.map fetchUrl2