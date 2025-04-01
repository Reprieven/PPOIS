from Model.database import Session, Athlete
from Model.xmlAdapter import XMLAdapter
from sqlalchemy import and_, or_

class Crud:
    data_source  = "db"
    xml_adapter = XMLAdapter()

    @staticmethod
    def set_data_source(source: str):
       Crud.data_source = source

    @staticmethod
    def add_data(name: str, team_role: str, position: str, titles: int, sport: str, category: str):
        new_athlete = Athlete(name=name, team_role=team_role, position=position, titles=titles,sport = sport, category=category)
        if Crud.data_source == "db":
            with Session() as session: 
                session.add(new_athlete)
                session.commit()
        else:
            Crud.xml_adapter.add_data(new_athlete)

    @staticmethod    
    def get_data():
        if Crud.data_source == "db":
            with Session() as session:
                atheletes = session.query(Athlete).all()
                return atheletes
        else:
            return Crud.xml_adapter.get_data()

    @staticmethod
    def search_by_name_or_sport(name = None, sport = None):
        if Crud.data_source == "db":
            with Session() as session: 
                query = session.query(Athlete)
                if name and sport:
                    query = query.filter(or_(Athlete.name.ilike(f"%{name}%"), Athlete.sport.ilike(f"%{sport}%")))
                elif name: 
                    query = query.filter(Athlete.name.ilike(f"%{name}%"))
                else: 
                    query = query.filter(Athlete.sport.ilike(f"%{sport}%"))

                return query.all()
        else:
            filters = {}
            if name: filters["name"] = name
            if sport: filters["sport"] = sport
            return Crud.xml_adapter.search(**filters)
    
    @staticmethod
    def search_by_name_or_category(name = None, category = None):
        if Crud.data_source == "db":
            with Session() as session: 
                query = session.query(Athlete)
                if name and category:
                    query = query.filter(or_(Athlete.name.ilike(f"%{name}%"), Athlete.category.ilike(f"%{category}%")))
                elif name: 
                    query = query.filter(Athlete.name.ilike(f"%{name}%"))
                else: 
                    query = query.filter(Athlete.category.ilike(f"%{category}%"))

                return query.all()
        else:
            filters = {}
            if name: filters["name"] = name
            if category: filters["category"] = category
            return Crud.xml_adapter.search(**filters)

    @staticmethod
    def search_by_titles(min = None, max= None):
        if Crud.data_source == "db":
            with Session() as session:
                query = session.query(Athlete)
                if min is not None and max is not None:
                    query = query.filter(and_(Athlete.titles>=min,Athlete.titles<=max))
                elif min is not None:
                    query = query.filter(Athlete.titles>=min)
                elif max is not None:
                    query = query.filter(Athlete.titles<=max)
                return query.all()
        else:
            return Crud.xml_adapter.search_by_titles(min, max)
    
    @staticmethod
    def delete_by_name_or_sport(name=None, sport=None):
        if not name and not sport:
            return 0
        if Crud.data_source == "db":
            with Session() as session:
                query = session.query(Athlete)
        
                if name and sport:
                    query = query.filter(or_(Athlete.name.ilike(f"%{name}%"), Athlete.sport.ilike(f"%{sport}%")))
                elif name:
                    query = query.filter(Athlete.name.ilike(f"%{name}%"))
                elif sport:
                    query = query.filter(Athlete.sport.ilike(f"%{sport}%"))

                deleted_count = query.delete(synchronize_session=False)
                session.commit()

                return deleted_count 
        else:
            filters = {}
            if name: filters["name"] = name
            if sport: filters["sport"] = sport
            return Crud.xml_adapter.delete(**filters)
        
    @staticmethod
    def delete_by_name_or_category(name=None, category=None):
        if not name and not category:
            return 0
        if Crud.data_source == "db":
            with Session() as session:
                query = session.query(Athlete)
                
                if name and category:
                    query = query.filter(or_(Athlete.name.ilike(f"%{name}%"), Athlete.category.ilike(f"%{category}%")))
                elif name:
                    query = query.filter(Athlete.name.ilike(f"%{name}%"))
                elif category:
                    query = query.filter(Athlete.category.ilike(f"%{category}%"))

                deleted_count = query.delete(synchronize_session=False)
                session.commit()

                return deleted_count
        else: 
            filters = {}
            if name: filters["name"] = name
            if category: filters["category"] = category
            return Crud.xml_adapter.delete(**filters)
        
    @staticmethod
    def delete_by_titles(min = None, max= None):
        if min is None and max is None:
            return 0
        if Crud.data_source == "db":
            with Session() as session:
                query = session.query(Athlete)
                if min is not None and max is not None:
                    query = query.filter(and_(Athlete.titles>=min,Athlete.titles<=max))
                elif min is not None:
                    query = query.filter(Athlete.titles>=min)
                elif max is not None:
                    query = query.filter(Athlete.titles<=max)
                deleted_count = query.delete(synchronize_session=False)
                session.commit()
                return deleted_count
        else:
            Crud.xml_adapter.delete_by_titles(min, max)
