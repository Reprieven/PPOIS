import tkinter as tk
from tkinter import ttk
from Controller.searchController import SearchResultsController
from View.searchView import SearchResultsView
class SearchWindow:
    def __init__(self, gui):
        self.gui = gui
        self.controller = gui.controller
        
    def show(self):
        self.window = tk.Toplevel(self.gui.root)
        self.window.title("Поиск")
        self.window.geometry("400x300")
        field_width = 30
        
        tk.Button(self.window, text="Поиск по ФИО и виду спорта", width=field_width, command=self.search_by_name_or_sport).pack(pady=5)
        tk.Button(self.window, text="Поиск по ФИО и разряду", width=field_width, command=self.search_by_name_or_category).pack(pady=5)
        tk.Button(self.window, text="Поиск по количеству титулов", width=field_width, command=self.search_by_titles).pack(pady=5)
        tk.Button(self.window, text="Закрыть", command=self.window.destroy).pack(pady=50)

    def create_results_window(self, results):
        results_window = tk.Toplevel(self.window)
        results_window.title("Результаты поиска")
        results_window.geometry("1200x600")
        
        search_controller = SearchResultsController(results)
        
        search_view = SearchResultsView(results_window, search_controller)
        search_controller.view = search_view
        
        search_controller.update_view()

    def search_by_name_or_sport(self):
        input_window = tk.Toplevel(self.window)
        input_window.title("Поиск по ФИО или виду спорта")
        input_window.geometry("300x200")

        tk.Label(input_window, text="ФИО(необязательно)").pack()
        name_entry = tk.Entry(input_window)
        name_entry.pack()

        tk.Label(input_window, text="Вид спорта(необязательно)").pack()
        sport_entry = tk.Entry(input_window)
        sport_entry.pack()

        def search():
            results = self.controller.search_by_name_sport(
                name=name_entry.get(),
                sport=sport_entry.get()
            )
            input_window.destroy()
            self.create_results_window(results)
        tk.Button(input_window, text="Найти", command=search).pack(pady=15)
        tk.Button(input_window, text="Закрыть", command=input_window.destroy).pack(anchor="s", pady=5)

    def search_by_name_or_category(self):
        input_window = tk.Toplevel(self.window)
        input_window.title("Поиск по ФИО или разряду")
        input_window.geometry("300x200")

        tk.Label(input_window, text="ФИО(необязательно)").pack()
        name_entry = tk.Entry(input_window)
        name_entry.pack()

        tk.Label(input_window, text="Разряд(необязательно)").pack()
        category_combobox = ttk.Combobox(input_window, values=["",
                                                            "1-й юношеский", 
                                                            "2-й разряд", 
                                                            "3-й разряд", 
                                                            "КМС", 
                                                            "Мастер спорта"], state="readonly")
        category_combobox.pack()
        category_combobox.set("") 

        def search():
            results = self.controller.search_by_name_category(
                name=name_entry.get(),
                category=category_combobox.get()
            )
            input_window.destroy()
            self.create_results_window(results)

        tk.Button(input_window, text="Найти", command=search).pack(pady=15)
        tk.Button(input_window, text="Закрыть", command=input_window.destroy).pack(anchor="s", pady=5)

    def search_by_titles(self):
        input_window = tk.Toplevel(self.window)
        input_window.title("Поиск по количеству титулов")
        input_window.geometry("300x200")

        tk.Label(input_window, text="Минимум титулов(необязательно)").pack()
        min_entry = tk.Entry(input_window)
        min_entry.pack()

        tk.Label(input_window, text="Максимум титулов(необязательно)").pack()
        max_entry = tk.Entry(input_window)
        max_entry.pack()

        def search():
            results = self.controller.search_titles(
                min=min_entry.get(),
                max=max_entry.get()
            )
            input_window.destroy()
            self.create_results_window(results)
        tk.Button(input_window, text="Поиск", command=search).pack(pady=15)
        tk.Button(input_window, text="Закрыть", command=input_window.destroy).pack(anchor="s", pady=5)