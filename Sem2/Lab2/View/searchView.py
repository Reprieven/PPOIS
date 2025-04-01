import tkinter as tk
from tkinter import ttk
class SearchResultsView:
    def __init__(self, root, controller):
        self.root = root
        self.controller = controller
        self.controller.view = self
        
        self.tree = ttk.Treeview(root, 
                               columns=("ФИО спортсмена", "Состав", "Позиция", "Титулы", "Вид спорта", "Разряд"), 
                               show="headings")
        self.tree.pack(expand=True, fill="both")
        
        for col in ("ФИО спортсмена", "Состав", "Позиция", "Титулы", "Вид спорта", "Разряд"):
            self.tree.heading(col, text=col)
            self.tree.column(col, width=100, anchor="center")
        
        self.pagination_frame = tk.Frame(root)
        self.pagination_frame.pack(side="bottom", fill="x", pady=10)
        
        self.records_label = tk.Label(self.pagination_frame, text="Записей на странице:")
        self.records_label.pack(side="left", padx=5)
        
        self.records_var = tk.StringVar(value=str(self.controller.records_per_page))
        self.records_entry = tk.Entry(self.pagination_frame, textvariable=self.records_var, width=5)
        self.records_entry.pack(side="left", padx=5)
        self.records_entry.bind("<Return>", lambda e: self.controller.change_records_per_page(self.records_var.get()))

        self.total_pages_label = tk.Label(self.pagination_frame, text="")
        self.total_pages_label.pack(side="left", padx=10)
        
        self.first_btn = tk.Button(self.pagination_frame, text="<<", command=self.controller.first_page)
        self.first_btn.pack(side="left", padx=2)
        
        self.prev_btn = tk.Button(self.pagination_frame, text="<", command=self.controller.prev_page)
        self.prev_btn.pack(side="left", padx=2)
        
        self.page_label = tk.Label(self.pagination_frame, text="1/1")
        self.page_label.pack(side="left", padx=5)
        
        self.next_btn = tk.Button(self.pagination_frame, text=">", command=self.controller.next_page)
        self.next_btn.pack(side="left", padx=2)
        
        self.last_btn = tk.Button(self.pagination_frame, text=">>", command=self.controller.last_page)
        self.last_btn.pack(side="left", padx=2)

    def update_table(self, athletes, current_page, total_pages, total_records):
        for row in self.tree.get_children():
            self.tree.delete(row)
            
        for athlete in athletes:
            self.tree.insert("", "end", values=(
                athlete.name, athlete.team_role, athlete.position,
                athlete.titles, athlete.sport, athlete.category
            ))
        
        self.update_pagination_controls(current_page, total_pages, total_records)

    def update_pagination_controls(self, current_page, total_pages, total_records):
        self.page_label.config(text=f"{current_page}/{total_pages}")
        self.total_pages_label.config(text=f"Всего записей: {total_records}")
        self.records_var.set(str(self.controller.records_per_page))
        
        self.first_btn.config(state="normal" if current_page > 1 else "disabled")
        self.prev_btn.config(state="normal" if current_page > 1 else "disabled")
        self.next_btn.config(state="normal" if current_page < total_pages else "disabled")
        self.last_btn.config(state="normal" if current_page < total_pages else "disabled")

    def open_error_window(self, message):
        window = tk.Toplevel(self.root)
        window.title("Ошибка ввода")
        window.geometry("500x200")
        tk.Label(window, text="Ошибка ввода:").pack(anchor="nw")
        tk.Label(window, text=message).pack(anchor="center")
        tk.Button(window, text="Закрыть", command=window.destroy).pack(anchor="s", pady=5)