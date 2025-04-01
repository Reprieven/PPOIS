from sqlalchemy import create_engine, Column, Integer, String, Enum
from sqlalchemy.orm import sessionmaker, declarative_base

DB_NAME = "Model/sports.db"
engine = create_engine(f"sqlite:///{DB_NAME}",echo=True)

Base = declarative_base()

class Athlete(Base):
    __tablename__ = 'athletes'
    id = Column(Integer, primary_key=True)
    name = Column(String, nullable=False)
    team_role = Column(Enum("основной","запасной", "n/a"), nullable=False)
    position = Column(String,nullable=False)
    titles = Column(Integer, default=0)
    sport = Column(String, nullable=False)
    category = Column(Enum("1-й юношеский", "2-й разряд", "3-й разряд", "КМС", "Мастер спорта"), nullable=False)

Base.metadata.create_all(engine) 

Session = sessionmaker(bind=engine)
