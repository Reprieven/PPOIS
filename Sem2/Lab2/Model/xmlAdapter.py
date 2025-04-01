import xml.etree.ElementTree as ET
from pathlib import Path
from typing import List, Dict, Optional
from Model.database import Athlete

class XMLAdapter:
    def __init__(self, file_name: str = "Model/sports.xml"):
        self.xml_file = Path(file_name)
    
    def is_file_exist(self):
        if not self.xml_file.exists():
            root = ET.Element("athletes")
            tree = ET.ElementTree(root)
            tree.write(self.xml_file, encoding="utf-8", xml_declaration=True)
    
    def athlete_to_dict(self, athlete: Athlete)->dict:
        athlete_dict = {
            "id": str(athlete.id),
            "name": athlete.name,
            "team_role": athlete.team_role,
            "position": athlete.position,
            "titles": str(athlete.titles),
            "sport": athlete.sport,
            "category": athlete.category
        }
        return athlete_dict
    
    def dict_to_athlete(self, data: Dict) -> Athlete:
        athlete = Athlete(
            name=data.get("name"),
            team_role=data.get("team_role"),
            position=data.get("position"),
            titles=int(data.get("titles", 0)),
            sport=data.get("sport"),
            category=data.get("category")
        )
        return athlete

    def add_data(self, athlete: Athlete)->None:
        self.is_file_exist()
        tree = ET.parse(self.xml_file)
        root = tree.getroot()
        athlete_elem = ET.SubElement(root, "athlete")
        for key, value in self.athlete_to_dict(athlete).items():
            ET.SubElement(athlete_elem, key).text = value
        
        tree.write(self.xml_file, encoding="utf-8", xml_declaration=True)
    
    def get_data(self)->List[Athlete]:
        self.is_file_exist()
        tree = ET.parse(self.xml_file)
        root = tree.getroot()
        athletes = []
        for athlete_elem in root.findall("athlete"):
            data = {child.tag: child.text for child in athlete_elem}
            athletes.append(self.dict_to_athlete(data))
        return athletes

    def search(self, **filters)->List[Athlete]:
        athletes = self.get_data()
        
        def matches(athlete: Athlete) -> bool:
            for key, value in filters.items():
                if value and str(getattr(athlete, key, "")).lower().strip() != str(value).lower().strip():
                    return False
            return True
        
        return [athlete for athlete in athletes if matches(athlete)]

    def search_by_titles(self, min = None, max = None) -> List[Athlete]:
        athletes = self.get_data()
        return [
            athlete for athlete in athletes
            if (min is None or athlete.titles >= min) and (max is None or athlete.titles <= max)
        ]
    
    def delete(self, **filters) -> int:
        self.is_file_exist()
        tree = ET.parse(self.xml_file)
        root = tree.getroot()
        
        to_keep = []
        deleted_count = 0
        
        for athlete_elem in root.findall("athlete"):
            data = {child.tag: child.text for child in athlete_elem}
            athlete = self.dict_to_athlete(data)
            
            should_delete = True
            for key, value in filters.items():
                if value and str(getattr(athlete, key, "")).lower().strip() != str(value).lower().strip():
                    should_delete = False
                    break
            
            if should_delete:
                deleted_count += 1
            else:
                to_keep.append(athlete_elem)

        new_root = ET.Element("athletes")
        for elem in to_keep:
            new_root.append(elem)
            
        new_tree = ET.ElementTree(new_root)
        new_tree.write(self.xml_file, encoding='utf-8', xml_declaration=True)
        
        return deleted_count
    
    def delete_by_titles(self, min: Optional[int] = None, max: Optional[int] = None) -> int:
        if min is None and max is None:
            return 0
            
        self._ensure_file_exists()
        tree = ET.parse(self.xml_file)
        root = tree.getroot()
        
        to_keep = []
        deleted_count = 0
        
        for athlete_elem in root.findall("athlete"):
            data = {child.tag: child.text for child in athlete_elem}
            titles = int(data.get("titles", 0))
            
            should_delete = False
            if min is not None and max is not None:
                should_delete = min <= titles <= max
            elif min is not None:
                should_delete = titles >= min
            elif max is not None:
                should_delete = titles <= max
            
            if should_delete:
                deleted_count += 1
            else:
                to_keep.append(athlete_elem)
        
        new_root = ET.Element("athletes")
        for elem in to_keep:
            new_root.append(elem)
            
        new_tree = ET.ElementTree(new_root)
        new_tree.write(self.xml_file, encoding='utf-8', xml_declaration=True)
        
        return deleted_count