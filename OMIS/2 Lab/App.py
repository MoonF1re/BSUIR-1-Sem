from flask import Flask, render_template, request, redirect, url_for, session
from Controller import AccessControlController

app = Flask(__name__)
app.secret_key = "supersecretkey"
controller = AccessControlController()

@app.route("/", methods=["GET", "POST"])
def login():
    if request.method == "POST":
        username = request.form["username"]
        password = request.form["password"]
        user = controller.authenticate_user(username, password)
        if user:
            session["username"] = user.username
            session["role"] = user.role
            return redirect(url_for("admin_menu" if user.role == "admin" else "employee_menu"))
        return "Invalid credentials. Please try again."
    return render_template("login.html")

@app.route("/admin_menu")
def admin_menu():
    if "role" in session and session["role"] == "admin":
        return render_template("admin_menu.html")
    return redirect(url_for("login"))

@app.route("/admin/register_user", methods=["GET", "POST"])
def register_user():
    if "role" in session and session["role"] == "admin":
        if request.method == "POST":
            username = request.form["username"]
            password = request.form["password"]
            role = request.form["role"]
            message = controller.register_user(username, password, role)
            return render_template("register_user.html", message=message)
        return render_template("register_user.html")
    return redirect(url_for("login"))

@app.route("/admin/view_users")
def view_users():
    if "role" in session and session["role"] == "admin":
        users = controller.get_all_users()
        return render_template("view_users.html", users=users)
    return redirect(url_for("login"))

@app.route("/admin/edit_access", methods=["GET", "POST"])
def edit_access():
    if "role" in session and session["role"] == "admin":
        if request.method == "POST":
            username = request.form["username"]
            new_zones = request.form.getlist("zones")
            message = controller.edit_user_access(username, new_zones)
            users = controller.get_all_users()
            return render_template("edit_access.html", message=message, users=users)
        users = controller.get_all_users()
        return render_template("edit_access.html", users=users)
    return redirect(url_for("login"))

@app.route("/admin/access_requests", methods=["GET", "POST"])
def access_requests():
    if "role" in session and session["role"] == "admin":
        if request.method == "POST":
            username = request.form["username"]
            zone = request.form["zone"]
            controller.delete_access_request(username, zone)
            access_requests = controller.get_access_requests()
            return render_template("access_requests.html", access_requests=access_requests)
        access_requests = controller.get_access_requests()
        return render_template("access_requests.html", access_requests=access_requests)
    return redirect(url_for("login"))

@app.route("/employee_menu")
def employee_menu():
    if "role" in session and session["role"] == "employee":
        return render_template("employee_menu.html")
    return redirect(url_for("login"))

@app.route("/employee/request_access", methods=["GET", "POST"])
def request_access():
    if "role" in session and session["role"] == "employee":
        if request.method == "POST":
            zone = request.form["zone"]
            message = controller.create_access_request(session["username"], zone)
            return render_template("request_access.html", message=message)
        return render_template("request_access.html")
    return redirect(url_for("login"))

@app.route("/employee/zones", methods=["GET"])
def view_zones():
    if "role" in session and session["role"] == "employee":
        zones = controller.get_accessible_zones(session["username"])
        return render_template("accessible_zones.html", zones=zones)
    return redirect(url_for("login"))

@app.route("/admin/visitors", methods=["GET", "POST"])
def manage_visitors():
    if "role" in session and session["role"] == "admin":
        if request.method == "POST":
            name = request.form["name"]
            visit_date = request.form["visit_date"]
            visit_time = request.form["visit_time"]
            purpose = request.form["purpose"]
            responsible_employee = request.form["responsible_employee"]
            message = controller.register_visitor(name, visit_date, visit_time, purpose, responsible_employee)
            return render_template("manage_visitors.html", message=message, visitors=controller.get_visitors())
        return render_template("manage_visitors.html", visitors=controller.get_visitors())
    return redirect(url_for("login"))

@app.route("/logout")
def logout():
    session.clear()
    return redirect(url_for("login"))

if __name__ == "__main__":
    app.run(debug=True)
