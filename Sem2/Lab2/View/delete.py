import tkinter as tk
from tkinter import ttk

class DeleteWindow:
    def __init__(self, gui):
        self.gui = gui
        self.controller = gui.controller
        
    def show(self):
        self.window = tk.Toplevel(self.gui.root)
        self.window.title("Удаление")
        self.window.geometry("400x300")
        field_width = 30

        tk.Button(self.window, text="Удалить по ФИО и виду спорта", width=field_width, command=self.delete_by_name_or_sport).pack(pady=5)
        tk.Button(self.window, text="Удалить по ФИО и разряду", width=field_width, command=self.delete_by_name_or_category).pack(pady=5)
        tk.Button(self.window, text="Удалить по количеству титулов", width=field_width, command=self.delete_by_titles).pack(pady=5)
        tk.Button(self.window, text="Закрыть", command=self.window.destroy).pack(pady=50)

    def delete_by_name_or_sport(self):
        input_window = tk.Toplevel(self.window)
        input_window.title("Удаление по ФИО или виду спорта")
        input_window.geometry("300x200")

        tk.Label(input_window, text="ФИО(необязательно)").pack()
        name_entry = tk.Entry(input_window)
        name_entry.pack()

        tk.Label(input_window, text="Вид спорта(необязательно)").pack()
        sport_entry = tk.Entry(input_window)
        sport_entry.pack()

        def delete():
            self.controller.delete_by_name_sport(
                name=name_entry.get(),
                sport=sport_entry.get()
            )
        tk.Button(input_window, text="Удалить", command=delete).pack(pady=15)
        tk.Button(input_window, text="Закрыть", command=input_window.destroy).pack(anchor="s", pady=5)

    def delete_by_name_or_category(self):
        input_window = tk.Toplevel(self.window)
        input_window.title("Удаление по ФИО или разряду")
        input_window.geometry("300x200")

        tk.Label(input_window, text="ФИО(необязательно)").pack()
        name_entry = tk.Entry(input_window)
        name_entry.pack()

        tk.Label(input_window, text="Разряд(необязательно)").pack()
        category_combobox = ttk.Combobox(input_window, values=[
            "", "1-й юношеский", "2-й разряд", "3-й разряд", "КМС", "Мастер спорта"
        ], state="readonly")
        category_combobox.pack()
        category_combobox.set("")

        def delete():
            self.controller.delete_by_name_category(
                name=name_entry.get(),
                category=category_combobox.get()
            )
        tk.Button(input_window, text="Удалить", command=delete).pack(pady=15)
        tk.Button(input_window, text="Закрыть", command=input_window.destroy).pack(anchor="s", pady=5)
    
    def delete_by_titles(self):
        input_window = tk.Toplevel(self.window)
        input_window.title("Удаление по количеству титулов")
        input_window.geometry("300x200")

        tk.Label(input_window, text="Минимум титулов(необязательно)").pack()
        min_entry = tk.Entry(input_window)
        min_entry.pack()

        tk.Label(input_window, text="Максимум титулов(необязательно)").pack()
        max_entry = tk.Entry(input_window)
        max_entry.pack()

        def delete():
            self.controller.delete_titles(
                min=min_entry.get(),
                max=max_entry.get()
                )
            input_window.destroy()
        tk.Button(input_window, text="Удалить", command=delete).pack(pady=15)
        tk.Button(input_window, text="Закрыть", command=input_window.destroy).pack(anchor="s", pady=5)