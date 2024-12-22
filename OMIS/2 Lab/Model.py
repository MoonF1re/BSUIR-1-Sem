import json
import os
from datetime import datetime

class User:
    def __init__(self, username: str, password: str, role: str, access_zones=None):
        self.username = username
        self.password = password
        self.role = role
        self.access_zones = access_zones if access_zones is not None else []

    def to_dict(self):
        return {
            "username": self.username,
            "password": self.password,
            "role": self.role,
            "access_zones": self.access_zones
        }

    @staticmethod
    def from_dict(data):
        return User(
            username=data["username"],
            password=data["password"],
            role=data["role"],
            access_zones=data.get("access_zones", [])
        )

class Visitor:
    def __init__(self, name: str, visit_date: str, visit_time: str, purpose: str, responsible_employee: str):
        self.name = name
        self.visit_date = visit_date
        self.visit_time = visit_time
        self.purpose = purpose
        self.responsible_employee = responsible_employee

    def to_dict(self):
        return {
            "name": self.name,
            "visit_date": self.visit_date,
            "visit_time": self.visit_time,
            "purpose": self.purpose,
            "responsible_employee": self.responsible_employee
        }

    @staticmethod
    def from_dict(data):
        return Visitor(
            name=data["name"],
            visit_date=data["visit_date"],
            visit_time=data["visit_time"],
            purpose=data["purpose"],
            responsible_employee=data["responsible_employee"]
        )

class Log:
    def __init__(self, action: str, username: str, timestamp: str = None):
        self.action = action
        self.username = username
        self.timestamp = timestamp if timestamp is not None else datetime.now().strftime("%Y-%m-%d %H:%M:%S")

    def to_dict(self):
        return {
            "action": self.action,
            "username": self.username,
            "timestamp": self.timestamp
        }

    @staticmethod
    def from_dict(data):
        return Log(
            action=data["action"],
            username=data["username"],
            timestamp=data["timestamp"]
        )

class AccessRequest:
    def __init__(self, username: str, requested_zone: str, status: str = "pending"):
        self.username = username
        self.requested_zone = requested_zone
        self.status = status

    def to_dict(self):
        return {
            "username": self.username,
            "requested_zone": self.requested_zone,
            "status": self.status
        }

    @staticmethod
    def from_dict(data):
        return AccessRequest(
            username=data["username"],
            requested_zone=data["requested_zone"],
            status=data["status"]
        )
