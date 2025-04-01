import tkinter as tk
from tkinter import ttk
class AddWindow:
    def __init__(self, gui):
        self.gui = gui
        self.controller = gui.controller
        
    def show(self):
        self.window = tk.Toplevel(self.gui.root)
        self.window.title("Добавление")
        self.window.geometry("400x300")

        tk.Button(self.window, text="Ввести данные вручную", command=self.add_manually, width=30).pack(anchor="center")
        tk.Button(self.window, text="Закрыть", command=self.window.destroy).pack(anchor="center", pady=10)

    def add_manually(self):
        input_window = tk.Toplevel(self.gui.root)
        input_window.title("Добавление вручную ")
        input_window.geometry("400x300")
        labels = ["ФИО спортсмена", "Состав", "Позиция", "Титулы", "Вид спорта", "Разряд"]
        entries = {}

        field_width = 30

        for i, label in enumerate(labels):
            tk.Label(input_window, text=label).grid(row=i, column=0, padx=5, pady=5)
            if label == "Состав":
                combobox = ttk.Combobox(input_window, values=["основной", "запасной", "n/a"], state="readonly", width=field_width)
                combobox.grid(row=i, column=1, padx=5, pady=5)
                combobox.set("основной") 
                entries[label] = combobox

            elif label == "Разряд":
                combobox = ttk.Combobox(input_window, values=["1-й юношеский", "2-й разряд", "3-й разряд", "КМС", "Мастер спорта"], 
                    state="readonly", 
                    width=field_width
                    )
                combobox.grid(row=i, column=1, padx=5, pady=5)
                combobox.set("1-й юношеский")  
                entries[label] = combobox

            else:
                entry = tk.Entry(input_window, width=field_width)
                entry.grid(row=i, column=1, padx=5, pady=5)
                entries[label] = entry

        def add():
            self.controller.add_athlete(
                entries["ФИО спортсмена"].get(),
                entries["Состав"].get(),
                entries["Позиция"].get(),
                entries["Титулы"].get(),
                entries["Вид спорта"].get(),
                entries["Разряд"].get()
            )
        tk.Button(input_window, text="Добавить", command=add).grid(row=len(labels), column=1, pady=5)
        tk.Button(input_window, text="Закрыть", command=input_window.destroy).grid(row=len(labels)+1, column=1)