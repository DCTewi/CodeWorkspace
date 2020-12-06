open System.Windows.Forms

let form = new Form (Width = 400, Height = 300, Visible = true, Text = "Hello")
form.TopMost <- true
form.Click.Add (fun _ -> printfn "form was clicked")
form.Show ()