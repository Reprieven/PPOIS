import tkinter as tk
from tkinter import ttk
from Controller.controller import *
from View.add import AddWindow
from View.delete import DeleteWindow
from View.search import SearchWindow
from tkinter import filedialog

class GUI: 
    def __init__(self, root):
        self.root = root
        self.root.title("Список спортсменов")
        self.root.geometry("1920x1080")

        self.button_frame = tk.Frame(root)
        self.button_frame.pack(side="top", anchor="nw", padx=10, pady=10)

        self.add_button = tk.Button(self.button_frame, text="Добавить спортсмена", command=self.open_add_window)
        self.add_button.grid(row=0, column=0, padx=5, pady=5)
        self.search_button = tk.Button(self.button_frame, text="Поиск спортсмена", command=self.open_search_window)
        self.search_button.grid(row=0, column=1, padx=5, pady=5)
        self.delete_button = tk.Button(self.button_frame, text="Удалить спортсмена", command=self.open_delete_window)
        self.delete_button.grid(row=0, column=2, padx=5, pady=5)
        self.change_source_button = tk.Button(self.button_frame, text="Изменить источник данных", command=self.open_change_data_source_window)
        self.change_source_button.grid(row=0, column=3, padx=5, pady=5)
        self.change_view_mod_button = tk.Button(self.button_frame, text="Изменить способ отображения данных", command=self.toggle_view_mode)
        self.change_view_mod_button.grid(row=0, column=4, padx=5, pady=5)

        self.view_mode = "table"

        self.data_container = tk.Frame(root)
        self.data_container.pack(expand=True, fill="both")

        self.tree = ttk.Treeview(self.data_container, columns=("ФИО спортсмена", "Состав", "Позиция", "Титулы", "Вид спорта", "Разряд"), show="headings")
        for col in ("ФИО спортсмена", "Состав", "Позиция", "Титулы", "Вид спорта", "Разряд"):
            self.tree.heading(col, text=col)
            self.tree.column(col, width=100, anchor="center")

        self.treeview = ttk.Treeview(self.data_container, show="tree")
        self.treeview.pack_forget()
        
        self.tree.pack(expand=True, fill="both")
        self.treeview.pack_forget()

        self.pagination_frame = tk.Frame(root)
        self.pagination_frame.pack(side="bottom", fill="x", pady=10)
        self.records_label = tk.Label(self.pagination_frame, text="Записей на странице:")
        self.records_label.pack(side="left", padx=5)
        self.records_var = tk.StringVar()

        self.records_entry = tk.Entry(self.pagination_frame, textvariable=self.records_var, width=5)
        self.records_entry.pack(side="left", padx=5)
        self.records_entry.bind("<Return>", self.change_records_per_page)

        self.total_pages_label = tk.Label(self.pagination_frame, text="")
        self.total_pages_label.pack(side="left", padx=10)

        self.first_btn = tk.Button(self.pagination_frame, text="<<", command=self.first_page)
        self.first_btn.pack(side="left", padx=2)
        
        self.prev_btn = tk.Button(self.pagination_frame, text="<", command=self.prev_page)
        self.prev_btn.pack(side="left", padx=2)
        
        self.page_label = tk.Label(self.pagination_frame, text="1/1")
        self.page_label.pack(side="left", padx=5)
        
        self.next_btn = tk.Button(self.pagination_frame, text=">", command=self.next_page)
        self.next_btn.pack(side="left", padx=2)
        
        self.last_btn = tk.Button(self.pagination_frame, text=">>", command=self.last_page)
        self.last_btn.pack(side="left", padx=2)

        self.controller = Controller(self)
        self.add_window = AddWindow(self)
        self.delete_window = DeleteWindow(self)
        self.search_window = SearchWindow(self)
        
        self.records_var.set(str(self.controller.records_per_page))
        self.controller.update_view()

    def change_to_table(self):
        self.view_mode = "table"
        self.treeview.pack_forget()
        self.tree.pack(expand=True, fill="both")
        self.controller.update_view()
    
    def change_to_tree(self):
        self.view_mode = "tree"
        self.tree.pack_forget()
        self.treeview.pack(expand=True, fill="both")
        self.controller.update_view()

    def toggle_view_mode(self):
        window = tk.Toplevel(self.root)
        window.title("Изменить способ отображения данных")
        window.geometry("400x150")
        tk.Button(window, text="Таблица", command=self.change_to_table).pack(anchor="center", pady=10)
        tk.Button(window, text="Дерево", command=self.change_to_tree).pack(anchor="center", pady=10)
        tk.Button(window, text="Закрыть", command=window.destroy).pack(anchor="s", pady=5)


    def update_table(self, athletes, current_page, total_pages, total_records):
        for row in self.tree.get_children():
            self.tree.delete(row)
        for row in self.treeview.get_children():
            self.treeview.delete(row)
            
        if self.view_mode == "table":
            for athlete in athletes:
                self.tree.insert("", "end", values=(
                    athlete.name, athlete.team_role, athlete.position,
                    athlete.titles, athlete.sport, athlete.category
                ))
        else:
            for athlete in athletes:
                athlete_node = self.treeview.insert("", "end", text=athlete.name, open=True)

                fields = [
                    ("Состав", athlete.team_role),
                    ("Позиция", athlete.position),
                    ("Титулы", athlete.titles),
                    ("Вид спорта", athlete.sport),
                    ("Разряд", athlete.category)
                ]
                
                for field_name, field_value in fields:
                    field_node = self.treeview.insert(athlete_node, "end", text=field_name, open=True)

                    self.treeview.insert(field_node, "end", text=str(field_value))
        
        self.update_pagination_controls(current_page, total_pages, total_records)

    def update_pagination_controls(self, current_page, total_pages, total_records):
        self.page_label.config(text=f"{current_page}/{total_pages}")
        self.total_pages_label.config(text=f"Всего записей: {total_records}")
        
        self.first_btn.config(state="normal" if current_page > 1 else "disabled")
        self.prev_btn.config(state="normal" if current_page > 1 else "disabled")
        self.next_btn.config(state="normal" if current_page < total_pages else "disabled")
        self.last_btn.config(state="normal" if current_page < total_pages else "disabled")

    def change_records_per_page(self, event=None):
        try:
            new_value = int(self.records_var.get())
            success = self.controller.change_records_per_page(new_value)
            if not success:
                self.records_var.set(str(self.controller.records_per_page))
                self.open_error_window("Введите натуральное положительное число")
        except ValueError:
            self.records_var.set(str(self.controller.records_per_page))
            self.open_error_window("Введите натуральное положительное число")
    
    def first_page(self):
        self.controller.first_page()
    
    def prev_page(self):
        self.controller.prev_page()
    
    def next_page(self):
        self.controller.next_page()
    
    def last_page(self):
        self.controller.last_page()

    def change_to_XML(self):
        self.controller.change_data_source("xml")
    
    def change_to_DB(self):
        self.controller.change_data_source("db")

    def open_error_window(self, message):
        window = tk.Toplevel(self.root)
        window.title("Ошибка ввода")
        window.geometry("400x150")
        tk.Label(window, text="Ошибка ввода:").pack(anchor="nw")
        tk.Label(window, text=message).pack(anchor="center")
        tk.Button(window, text="Закрыть", command=window.destroy).pack(anchor="s", pady=5)
    
    def open_deleted_count_window(self, message):
        window = tk.Toplevel(self.root)
        window.title("Количество удаленных")
        window.geometry("400x150")
        tk.Label(window, text=message).pack(anchor="center")
        tk.Button(window, text="Закрыть", command=window.destroy).pack(anchor="s", pady=5)
    
    def open_change_data_source_window(self):
        window = tk.Toplevel(self.root)
        window.title("Изменение источника данных")
        window.geometry("400x200") 
        
        tk.Label(window, text="Выберите источник данных:").pack(pady=5)
        
        tk.Button(window, text="База данных", command=self.change_to_DB).pack(pady=5)
        tk.Button(window, text="XML", command=self.change_to_XML).pack(pady=5)
    
        tk.Button(window,text="XML (выбрать файл...)",command=self.open_xml_file_dialog).pack(pady=5)
        
        tk.Button(window, text="Закрыть", command=window.destroy).pack(pady=5)
    
    def open_xml_file_dialog(self):
        file_path = filedialog.askopenfilename(
            title="Выберите XML-файл",
            filetypes=[("XML files", "*.xml")],
            defaultextension=".xml"
        )
        self.controller.change_xml_file(file_path)
        

    def open_add_window(self):
        self.add_window.show()

    def open_delete_window(self):
        self.delete_window.show()

    def open_search_window(self):
        self.search_window.show()