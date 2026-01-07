import tkinter as tk 
import time 

root = tk.Tk()
root.title("Digital Clock")
root.resizable(False,False)

label = tk.Label(
    root,
    font=("Helvetica",48),
    padx=20,
    pady=20
)
label.pack()

def update_clock():
    label.config(text=time.strftime("%H:%M:%S"))
    root.after(1000,update_clock)

update_clock()
root.mainloop()


