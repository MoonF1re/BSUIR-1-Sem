import json
import os
from Model import User, Log, AccessRequest, Visitor

class AccessControlController:
    def __init__(self):
        self.data_dir = "data"
        os.makedirs(self.data_dir, exist_ok=True)
        self.users_file = os.path.join(self.data_dir, "users.json")
        self.visitors_file = os.path.join(self.data_dir, "visitors.json")
        self.logs_file = os.path.join(self.data_dir, "logs.json")
        self.access_requests_file = os.path.join(self.data_dir, "access_requests.json")

        self.load_data()
        self.ensure_admin_exists()

    def ensure_admin_exists(self):
        admin_exists = any(user.username == "admin" and user.role == "admin" for user in self.users)
        if not admin_exists:
            self.register_user("admin", "admin123", "admin")
            print("Admin account created.")

    def load_data(self):
        self.users = self.load_from_file(self.users_file, User)
        self.visitors = self.load_from_file(self.visitors_file, Visitor)
        self.logs = self.load_from_file(self.logs_file, Log)
        self.access_requests = self.load_from_file(self.access_requests_file, AccessRequest)

    def save_data(self):
        self.save_to_file(self.users_file, self.users)
        self.save_to_file(self.visitors_file, self.visitors)
        self.save_to_file(self.logs_file, self.logs)
        self.save_to_file(self.access_requests_file, self.access_requests)

    def load_from_file(self, file_path, cls):
        if os.path.exists(file_path):
            with open(file_path, "r") as file:
                data = json.load(file)
                return [cls.from_dict(item) for item in data]
        return []

    def save_to_file(self, file_path, data):
        with open(file_path, "w") as file:
            json.dump([item.to_dict() for item in data], file, indent=4)

    def register_user(self, username, password, role):
        if any(user.username == username for user in self.users):
            return "User already exists."
        self.users.append(User(username, password, role))
        self.log_action("register", username)
        self.save_data()
        return "User registered successfully."

    def authenticate_user(self, username, password):
        for user in self.users:
            if user.username == username and user.password == password:
                self.log_action("login", username)
                return user
        return None

    def log_action(self, action, username):
        self.logs.append(Log(action, username))
        self.save_data()

    def create_access_request(self, username, zone):
        self.access_requests.append(AccessRequest(username, zone))
        self.log_action("request_access", username)
        self.save_data()
        return "Access request created."

    def approve_access_request(self, username, zone):
        user = next((user for user in self.users if user.username == username), None)
        if user:
            user.access_zones.append(zone)
            self.log_action("approve_access", username)
            self.save_data()
            return "Access granted."
        return "User not found."

    def get_user_logs(self, username):
        return [log for log in self.logs if log.username == username]

    def get_accessible_zones(self, username):
        user = next((user for user in self.users if user.username == username), None)
        return user.access_zones if user else []

    def register_visitor(self, name, visit_date, visit_time, purpose, responsible_employee):
        self.visitors.append(Visitor(name, visit_date, visit_time, purpose, responsible_employee))
        self.log_action("register_visitor", name)
        self.save_data()
        return "Visitor registered successfully."

    def get_visitors(self):
        return self.visitors

    def get_all_users(self):
        return self.users

    def edit_user_access(self, username, new_zones):
        user = next((user for user in self.users if user.username == username), None)
        if user:
            user.access_zones = new_zones
            self.log_action("edit_access", username)
            self.save_data()
            return "Access updated successfully."
        return "User not found."

    def get_access_requests(self):
        return self.access_requests

    def delete_access_request(self, username, zone):
        self.access_requests = [
            request for request in self.access_requests if not (request.username == username and request.requested_zone == zone)
        ]
        self.log_action("delete_access_request", username)
        self.save_data()
        return "Access request deleted."
