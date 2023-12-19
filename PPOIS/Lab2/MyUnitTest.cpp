#include "pch.h"
#include "CppUnitTest.h"
#include "../PPOIS_Lab_2/Vehicle.h"
#include "../PPOIS_Lab_2/Car.h"
#include "../PPOIS_Lab_2/Motorcycle.h"
#include "../PPOIS_Lab_2/Crane.h"
#include "../PPOIS_Lab_2/TowTruck.h"
#include "../PPOIS_Lab_2/Truck.h"
#include "../PPOIS_Lab_2/ElectricCar.h"
#include "../PPOIS_Lab_2/HybridCar.h"
#include "../PPOIS_Lab_2/Formula_1.h"
#include "../PPOIS_Lab_2/SportCar.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MyUnitTest
{
    TEST_CLASS(VehicleTest)
    {
    public:
        TEST_METHOD(TestRepair)
        {
            // �������� ������� Vehicle
            Vehicle vehicle("Toyota", "Camry", 2022);

            // ����� ������ repair
            std::ostringstream output;
            std::streambuf* oldCoutBuffer = std::cout.rdbuf();
            std::cout.rdbuf(output.rdbuf()); // ��������������� ������ � ����� output
            vehicle.repair();
            std::cout.rdbuf(oldCoutBuffer); // �������������� ������ � ����������� �����

            // �������� ���������� ������
            std::string expectedOutput = "������ ������������� �������� Toyota Camry\n";
            Assert::AreEqual(expectedOutput, output.str());
        }

        TEST_METHOD(TestDisplay)
        {
            // �������� ������� Vehicle
            Vehicle vehicle("Toyota", "Camry", 2022);

            // ����� ������ display
            std::ostringstream output;
            std::streambuf* oldCoutBuffer = std::cout.rdbuf();
            std::cout.rdbuf(output.rdbuf()); // ��������������� ������ � ����� output
            vehicle.display();
            std::cout.rdbuf(oldCoutBuffer); // �������������� ������ � ����������� �����

            // �������� ���������� ������
            std::string expectedOutput = "�����: Toyota\n������: Camry\n��� �������: 2022\n";
            Assert::AreEqual(expectedOutput, output.str());
        }
    };
    TEST_CLASS(CarTest) 
    {
        public:
            TEST_METHOD(TestCar) {
                // �������� ������� 
                Car cars("BMW","X5",2022,4,"V8");

                // ����� ������ repair
                std::ostringstream output;
                std::streambuf* oldCoutBuffer = std::cout.rdbuf();
                std::cout.rdbuf(output.rdbuf()); // ��������������� ������ � ����� output
                cars.startEngine();
                std::cout.rdbuf(oldCoutBuffer); // �������������� ������ � ����������� �����

                // �������� ���������� ������
                std::string expectedOutput = "������ ��������� ���������� BMW X5\n";
                Assert::AreEqual(expectedOutput, output.str());
            }

            TEST_METHOD(TestCar2) {
                // �������� ������� 
                Car cars("BMW", "X5", 2022, 4, "V8");

                // ����� ������ repair
                std::ostringstream output;
                std::streambuf* oldCoutBuffer = std::cout.rdbuf();
                std::cout.rdbuf(output.rdbuf()); // ��������������� ������ � ����� output
                cars.stopEngine();
                std::cout.rdbuf(oldCoutBuffer); // �������������� ������ � ����������� �����

                // �������� ���������� ������
                std::string expectedOutput = "��������� ��������� ���������� BMW X5\n";
                Assert::AreEqual(expectedOutput, output.str());
            }
    };
    TEST_CLASS(MotorcycleTets) {
         public:
            TEST_METHOD(TestMotorcycle) {
                // �������� ������� 
                Motorcycle m("BMX","Best",2010,"V5","Racing");

                // ����� ������ repair
                std::ostringstream output;
                std::streambuf* oldCoutBuffer = std::cout.rdbuf();
                std::cout.rdbuf(output.rdbuf()); // ��������������� ������ � ����� output
                m.drive();
                std::cout.rdbuf(oldCoutBuffer); // �������������� ������ � ����������� �����

                // �������� ���������� ������
                std::string expectedOutput = "������� �� ��������� BMX Best\n";
                Assert::AreEqual(expectedOutput, output.str());
            }

            TEST_METHOD(TestMotorcycle2) {
                // �������� ������� 
                Motorcycle m("BMX", "Best", 2010, "V5", "Racing");

                // ����� ������ repair
                std::ostringstream output;
                std::streambuf* oldCoutBuffer = std::cout.rdbuf();
                std::cout.rdbuf(output.rdbuf()); // ��������������� ������ � ����� output
                m.feints();
                std::cout.rdbuf(oldCoutBuffer); // �������������� ������ � ����������� �����

                // �������� ���������� ������
                std::string expectedOutput = "������� ���� �� ��������� BMX Best\n";
                Assert::AreEqual(expectedOutput, output.str());
            }
    };
    TEST_CLASS(CraneTest) {
        public:
            TEST_METHOD(TestCrane) {
                // �������� ������� 
                Crane crane("Crane","Goo",2020,100);

                // ����� ������ repair
                std::ostringstream output;
                std::streambuf* oldCoutBuffer = std::cout.rdbuf();
                std::cout.rdbuf(output.rdbuf()); // ��������������� ������ � ����� output
                crane.lift();
                std::cout.rdbuf(oldCoutBuffer); // �������������� ������ � ����������� �����

                // �������� ���������� ������
                std::string expectedOutput = "������ ����� � ������� ����� Crane Goo\n";
                Assert::AreEqual(expectedOutput, output.str());
            }
            TEST_METHOD(TestCrane2) {
                // �������� ������� 
                Crane crane("Crane", "Goo", 2020, 100);

                // ����� ������ repair
                std::ostringstream output;
                std::streambuf* oldCoutBuffer = std::cout.rdbuf();
                std::cout.rdbuf(output.rdbuf()); // ��������������� ������ � ����� output
                crane.liftStop();
                std::cout.rdbuf(oldCoutBuffer); // �������������� ������ � ����������� �����

                // �������� ���������� ������
                std::string expectedOutput = "�������� ���� � ������� ����� Crane Goo\n";
                Assert::AreEqual(expectedOutput, output.str());
            }

    };
    TEST_CLASS(TowTruckTest) {
        public:
            TEST_METHOD(TestTow) {
                // �������� �������
                TowTruck t("Town","Truck",2000,"G7");

                // ����� ������ repair
                std::ostringstream output;
                std::streambuf* oldCoutBuffer = std::cout.rdbuf();
                std::cout.rdbuf(output.rdbuf()); // ��������������� ������ � ����� output
                t.tow();
                std::cout.rdbuf(oldCoutBuffer); // �������������� ������ � ����������� �����

                // �������� ���������� ������
                std::string expectedOutput = "���������� ������������� �������� � ������� ���������� Town Truck\n";
                Assert::AreEqual(expectedOutput, output.str());
            }

            TEST_METHOD(TestTow2) {
                // �������� �������
                TowTruck t("Town", "Truck", 2000, "G7");

                // ����� ������ repair
                std::ostringstream output;
                std::streambuf* oldCoutBuffer = std::cout.rdbuf();
                std::cout.rdbuf(output.rdbuf()); // ��������������� ������ � ����� output
                t.towStop();
                std::cout.rdbuf(oldCoutBuffer); // �������������� ������ � ����������� �����

                // �������� ���������� ������
                std::string expectedOutput = "���������� ���������� ������������� �������� � ������� ���������� Town Truck\n";
                Assert::AreEqual(expectedOutput, output.str());
            }
    
    };
    TEST_CLASS(TruckTest) {
    public:
        TEST_METHOD(TestTruck) {
            // �������� ������� 
            Truck tt("Truck","Mers",2010,120);

            // ����� ������ repair
            std::ostringstream output;
            std::streambuf* oldCoutBuffer = std::cout.rdbuf();
            std::cout.rdbuf(output.rdbuf()); // ��������������� ������ � ����� output
            tt.loadCargo();
            std::cout.rdbuf(oldCoutBuffer); // �������������� ������ � ����������� �����

            // �������� ���������� ������
            std::string expectedOutput = "�������� ����� � �������� Truck Mers\n";
            Assert::AreEqual(expectedOutput, output.str());
        }

        TEST_METHOD(TestTruck2) {
            // �������� �������
            Truck tt("Truck", "Mers", 2010, 120);

            // ����� ������ repair
            std::ostringstream output;
            std::streambuf* oldCoutBuffer = std::cout.rdbuf();
            std::cout.rdbuf(output.rdbuf()); // ��������������� ������ � ����� output
            tt.unloadCargo();
            std::cout.rdbuf(oldCoutBuffer); // �������������� ������ � ����������� �����

            // �������� ���������� ������
            std::string expectedOutput = "�������� ����� �� ��������� Truck Mers\n";
            Assert::AreEqual(expectedOutput, output.str());
        }
    
    };
    TEST_CLASS(ElectricCarTest) {
         public:
            TEST_METHOD(TestElectricCar) {
                // �������� �������
                ElectricCar el("Tesla", "X", 2021, 4, 500,"G6",true);

                // ����� ������ repair
                std::ostringstream output;
                std::streambuf* oldCoutBuffer = std::cout.rdbuf();
                std::cout.rdbuf(output.rdbuf()); // ��������������� ������ � ����� output
                el.charge();
                std::cout.rdbuf(oldCoutBuffer); // �������������� ������ � ����������� �����

                // �������� ���������� ������
                std::string expectedOutput = "������� ������������� Tesla X\n";
                Assert::AreEqual(expectedOutput, output.str());
            }
            TEST_METHOD(TestElectricCar2) {
                // �������� �������
                ElectricCar el("Tesla", "X", 2021, 4, 500, "G6", true);

                // ����� ������ repair
                std::ostringstream output;
                std::streambuf* oldCoutBuffer = std::cout.rdbuf();
                std::cout.rdbuf(output.rdbuf()); // ��������������� ������ � ����� output
                el.eco();
                std::cout.rdbuf(oldCoutBuffer); // �������������� ������ � ����������� �����

                // �������� ���������� ������
                std::string expectedOutput = "�������� ������ ����� � Tesla X\n";
                Assert::AreEqual(expectedOutput, output.str());
            }
    
    };
    TEST_CLASS(HubridCarTest) {
    public:
        TEST_METHOD(TestHubridCar) {
            // �������� �������
            HybridCar el("Tesla", "X", 2021, 4, 500,500,"G6");

            // ����� ������ repair
            std::ostringstream output;
            std::streambuf* oldCoutBuffer = std::cout.rdbuf();
            std::cout.rdbuf(output.rdbuf()); // ��������������� ������ � ����� output
            el.refillFuel();
            std::cout.rdbuf(oldCoutBuffer); // �������������� ������ � ����������� �����

            // �������� ���������� ������
            std::string expectedOutput = "�������� ���������� ������������� Tesla X\n";
            Assert::AreEqual(expectedOutput, output.str());
        }
    
    };
    TEST_CLASS(Formula_1Test) {
    public:
        TEST_METHOD(TestFormula_1) {
            // �������� �������
            Formula_1 f1("Ferrari","GH56",2023,2,250,"H600");

            // ����� ������ repair
            std::ostringstream output;
            std::streambuf* oldCoutBuffer = std::cout.rdbuf();
            std::cout.rdbuf(output.rdbuf()); // ��������������� ������ � ����� output
            f1.accelerates();
            std::cout.rdbuf(oldCoutBuffer); // �������������� ������ � ����������� �����

            // �������� ���������� ������
            std::string expectedOutput = "����������� �� ������������ �������� Ferrari GH56\n";
            Assert::AreEqual(expectedOutput, output.str());
        }

        TEST_METHOD(TestFormula_1_2) {
            // �������� �������
            Formula_1 f1("Ferrari", "GH56", 2023, 2, 250, "H600");

            // ����� ������ repair
            std::ostringstream output;
            std::streambuf* oldCoutBuffer = std::cout.rdbuf();
            std::cout.rdbuf(output.rdbuf()); // ��������������� ������ � ����� output
            f1.change();
            std::cout.rdbuf(oldCoutBuffer); // �������������� ������ � ����������� �����

            // �������� ���������� ������
            std::string expectedOutput = "����� �������� � ������ Ferrari GH56\n";
            Assert::AreEqual(expectedOutput, output.str());
        }

    };
    TEST_CLASS(SportCarTest)
    {
    public:

        TEST_METHOD(TestSportCar) {
            // �������� ������� 
            SportCar sport("Ford", "Mustang", 5000, 2015, 4, 200, "V8");

            // ����� ������ repair
            std::ostringstream output;
            std::streambuf* oldCoutBuffer = std::cout.rdbuf();
            std::cout.rdbuf(output.rdbuf()); // ��������������� ������ � ����� output
            sport.stops();
            std::cout.rdbuf(oldCoutBuffer); // �������������� ������ � ����������� �����

            // �������� ���������� ������
            std::string expectedOutput = "������ ��������������� Ford Mustang\n";
            Assert::AreEqual(expectedOutput, output.str());
        }

        TEST_METHOD(TestSportCar2) {
            // �������� ������� 
            SportCar sport("Ford", "Mustang", 5000, 2015, 4, 200, "V8");

            // ����� ������ repair
            std::ostringstream output;
            std::streambuf* oldCoutBuffer = std::cout.rdbuf();
            std::cout.rdbuf(output.rdbuf()); // ��������������� ������ � ����� output
            sport.drift();
            std::cout.rdbuf(oldCoutBuffer); // �������������� ������ � ����������� �����

            // �������� ���������� ������
            std::string expectedOutput = "������ ������� Ford Mustang\n";
            Assert::AreEqual(expectedOutput, output.str());
        }
    };
}
