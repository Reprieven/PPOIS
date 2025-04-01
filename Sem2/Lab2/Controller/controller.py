from Model.crud import Crud


class Controller:
    def __init__(self, view):
        self.view = view
        self.current_page = 1
        self.records_per_page = 10
        self.all_athletes = []
        self.load_data()

    def load_data(self):
        self.all_athletes = Crud.get_data()
        self.update_view()
    
    def change_data_source(self, source: str):
        Crud.set_data_source(source)
        self.load_data()

    def update_view(self):
        total_pages = self.calculate_total_pages()
        
        if self.current_page > total_pages and total_pages > 0:
            self.current_page = total_pages
        
        page_athletes = self.get_current_page_data()
        self.view.update_table(
            athletes=page_athletes,
            current_page=self.current_page,
            total_pages=total_pages,
            total_records=len(self.all_athletes)
        )

    def calculate_total_pages(self):
        if len(self.all_athletes) == 0:
            return 1
        return max(1, (len(self.all_athletes) + self.records_per_page - 1) // self.records_per_page)

    def get_current_page_data(self):
        start_idx = (self.current_page - 1) * self.records_per_page
        end_idx = min(start_idx + self.records_per_page, len(self.all_athletes))
        return self.all_athletes[start_idx:end_idx]

    def change_page(self, page):
        if 1 <= page <= self.calculate_total_pages():
            self.current_page = page
            self.update_view()

    def change_records_per_page(self, new_value):
        if new_value < 1:
            return False
        self.records_per_page = new_value
        self.current_page = 1
        self.update_view()
        return True

    def first_page(self):
        self.change_page(1)
    
    def prev_page(self):
        self.change_page(self.current_page - 1)
    
    def next_page(self):
        self.change_page(self.current_page + 1)
    
    def last_page(self):
        self.change_page(self.calculate_total_pages())

    def validate_athlete_data(self, name: str, position: str, sport: str, titles: str):
        errors = []
        
        if not name.strip():
            errors.append("Спортсмен не может не иметь ФИО")
        if not position.strip():
            errors.append("Спортсмен не может не иметь позиции")
        if not sport.strip():
            errors.append("Спортсмен не может не иметь вида спорта")
        
        if not titles.strip():
            errors.append("Введите количество титулов")
        else:
            try:
                titles_int = int(titles)
                if titles_int < 0:
                    errors.append("Количество титулов не может быть отрицательным")
            except ValueError:
                errors.append("Количество титулов должно быть целым числом")
        
        return errors if errors else None

    def add_athlete(self, name: str, team_role: str, position: str, titles: str, sport: str, category: str):
        errors = self.validate_athlete_data(name, position, sport, titles)
        if errors:
            self.view.open_error_window("\n".join(errors))
            return

        Crud.add_data(name, team_role, position, int(titles), sport, category)
        self.load_data()

    def search_by_name_sport(self, name=None, sport=None):
        name = name.strip() if name else None
        sport = sport.strip() if sport else None
        athletes = Crud.search_by_name_or_sport(name, sport)
        return athletes
    
    def search_by_name_category(self, name=None, category=None):
        name = name.strip() if name else None
        category = category.strip() if category else None
        athletes = Crud.search_by_name_or_category(name, category)
        return athletes

    def search_titles(self, min:int =None, max:int =None):
        try:
            min_int = int(min) if min else None
            max_int = int(max) if max else None
            
            if min_int is not None and min_int < 0:
                raise ValueError("Минимум титулов не может быть отрицательным")
            if max_int is not None and max_int < 0:
                raise ValueError("Максимум титулов не может быть отрицательным")
            
            athletes = Crud.search_by_titles(min_int, max_int)
            return athletes
        except ValueError as e:
            self.view.open_error_window(str(e)) 

    def delete_by_name_sport(self, name, sport):
        name = name.strip() if name else None
        sport = sport.strip() if sport else None
        deleted_count = Crud.delete_by_name_or_sport(name, sport)
        self.handle_deletion_result(deleted_count)
    
    def delete_by_name_category(self, name, category):
        name = name.strip() if name else None
        category = category.strip() if category else None
        deleted_count = Crud.delete_by_name_or_category(name, category)
        self.handle_deletion_result(deleted_count)

    def delete_titles(self, min:int =None, max:int =None):
        try:
            min_int = int(min) if min else None
            max_int = int(max) if max else None
            
            if min_int is not None and min_int < 0:
                raise ValueError("Минимум титулов не может быть отрицательным")
            if max_int is not None and max_int < 0:
                raise ValueError("Максимум титулов не может быть отрицательным")
            
            deleted_count = Crud.delete_by_titles(min_int, max_int)
            self.handle_deletion_result(deleted_count)
        except ValueError as e:
            self.view.open_error_window(str(e)) 

    def handle_deletion_result(self, deleted_count):
        if deleted_count > 0:
            self.view.open_deleted_count_window(f"Удалено {deleted_count} спортсменов")
        else:
            self.view.open_deleted_count_window("Спортсмены не найдены, ничего не удалено")
        self.load_data()