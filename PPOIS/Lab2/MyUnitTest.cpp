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
            // Создание объекта Vehicle
            Vehicle vehicle("Toyota", "Camry", 2022);

            // Вызов метода repair
            std::ostringstream output;
            std::streambuf* oldCoutBuffer = std::cout.rdbuf();
            std::cout.rdbuf(output.rdbuf()); // Перенаправление вывода в поток output
            vehicle.repair();
            std::cout.rdbuf(oldCoutBuffer); // Восстановление вывода в стандартный поток

            // Проверка ожидаемого вывода
            std::string expectedOutput = "Ремонт транспортного средства Toyota Camry\n";
            Assert::AreEqual(expectedOutput, output.str());
        }

        TEST_METHOD(TestDisplay)
        {
            // Создание объекта Vehicle
            Vehicle vehicle("Toyota", "Camry", 2022);

            // Вызов метода display
            std::ostringstream output;
            std::streambuf* oldCoutBuffer = std::cout.rdbuf();
            std::cout.rdbuf(output.rdbuf()); // Перенаправление вывода в поток output
            vehicle.display();
            std::cout.rdbuf(oldCoutBuffer); // Восстановление вывода в стандартный поток

            // Проверка ожидаемого вывода
            std::string expectedOutput = "Марка: Toyota\nМодель: Camry\nГод выпуска: 2022\n";
            Assert::AreEqual(expectedOutput, output.str());
        }
    };
    TEST_CLASS(CarTest) 
    {
        public:
            TEST_METHOD(TestCar) {
                // Создание объекта 
                Car cars("BMW","X5",2022,4,"V8");

                // Вызов метода repair
                std::ostringstream output;
                std::streambuf* oldCoutBuffer = std::cout.rdbuf();
                std::cout.rdbuf(output.rdbuf()); // Перенаправление вывода в поток output
                cars.startEngine();
                std::cout.rdbuf(oldCoutBuffer); // Восстановление вывода в стандартный поток

                // Проверка ожидаемого вывода
                std::string expectedOutput = "Запуск двигателя автомобиля BMW X5\n";
                Assert::AreEqual(expectedOutput, output.str());
            }

            TEST_METHOD(TestCar2) {
                // Создание объекта 
                Car cars("BMW", "X5", 2022, 4, "V8");

                // Вызов метода repair
                std::ostringstream output;
                std::streambuf* oldCoutBuffer = std::cout.rdbuf();
                std::cout.rdbuf(output.rdbuf()); // Перенаправление вывода в поток output
                cars.stopEngine();
                std::cout.rdbuf(oldCoutBuffer); // Восстановление вывода в стандартный поток

                // Проверка ожидаемого вывода
                std::string expectedOutput = "Остановка двигателя автомобиля BMW X5\n";
                Assert::AreEqual(expectedOutput, output.str());
            }
    };
    TEST_CLASS(MotorcycleTets) {
         public:
            TEST_METHOD(TestMotorcycle) {
                // Создание объекта 
                Motorcycle m("BMX","Best",2010,"V5","Racing");

                // Вызов метода repair
                std::ostringstream output;
                std::streambuf* oldCoutBuffer = std::cout.rdbuf();
                std::cout.rdbuf(output.rdbuf()); // Перенаправление вывода в поток output
                m.drive();
                std::cout.rdbuf(oldCoutBuffer); // Восстановление вывода в стандартный поток

                // Проверка ожидаемого вывода
                std::string expectedOutput = "Поездка на мотоцикле BMX Best\n";
                Assert::AreEqual(expectedOutput, output.str());
            }

            TEST_METHOD(TestMotorcycle2) {
                // Создание объекта 
                Motorcycle m("BMX", "Best", 2010, "V5", "Racing");

                // Вызов метода repair
                std::ostringstream output;
                std::streambuf* oldCoutBuffer = std::cout.rdbuf();
                std::cout.rdbuf(output.rdbuf()); // Перенаправление вывода в поток output
                m.feints();
                std::cout.rdbuf(oldCoutBuffer); // Восстановление вывода в стандартный поток

                // Проверка ожидаемого вывода
                std::string expectedOutput = "Сделать финт на мотоцикле BMX Best\n";
                Assert::AreEqual(expectedOutput, output.str());
            }
    };
    TEST_CLASS(CraneTest) {
        public:
            TEST_METHOD(TestCrane) {
                // Создание объекта 
                Crane crane("Crane","Goo",2020,100);

                // Вызов метода repair
                std::ostringstream output;
                std::streambuf* oldCoutBuffer = std::cout.rdbuf();
                std::cout.rdbuf(output.rdbuf()); // Перенаправление вывода в поток output
                crane.lift();
                std::cout.rdbuf(oldCoutBuffer); // Восстановление вывода в стандартный поток

                // Проверка ожидаемого вывода
                std::string expectedOutput = "Подъем груза с помощью крана Crane Goo\n";
                Assert::AreEqual(expectedOutput, output.str());
            }
            TEST_METHOD(TestCrane2) {
                // Создание объекта 
                Crane crane("Crane", "Goo", 2020, 100);

                // Вызов метода repair
                std::ostringstream output;
                std::streambuf* oldCoutBuffer = std::cout.rdbuf();
                std::cout.rdbuf(output.rdbuf()); // Перенаправление вывода в поток output
                crane.liftStop();
                std::cout.rdbuf(oldCoutBuffer); // Восстановление вывода в стандартный поток

                // Проверка ожидаемого вывода
                std::string expectedOutput = "Спустить груз с помощью крана Crane Goo\n";
                Assert::AreEqual(expectedOutput, output.str());
            }

    };
    TEST_CLASS(TowTruckTest) {
        public:
            TEST_METHOD(TestTow) {
                // Создание объекта
                TowTruck t("Town","Truck",2000,"G7");

                // Вызов метода repair
                std::ostringstream output;
                std::streambuf* oldCoutBuffer = std::cout.rdbuf();
                std::cout.rdbuf(output.rdbuf()); // Перенаправление вывода в поток output
                t.tow();
                std::cout.rdbuf(oldCoutBuffer); // Восстановление вывода в стандартный поток

                // Проверка ожидаемого вывода
                std::string expectedOutput = "Буксировка транспортного средства с помощью эвакуатора Town Truck\n";
                Assert::AreEqual(expectedOutput, output.str());
            }

            TEST_METHOD(TestTow2) {
                // Создание объекта
                TowTruck t("Town", "Truck", 2000, "G7");

                // Вызов метода repair
                std::ostringstream output;
                std::streambuf* oldCoutBuffer = std::cout.rdbuf();
                std::cout.rdbuf(output.rdbuf()); // Перенаправление вывода в поток output
                t.towStop();
                std::cout.rdbuf(oldCoutBuffer); // Восстановление вывода в стандартный поток

                // Проверка ожидаемого вывода
                std::string expectedOutput = "Остановить буксировку транспортного средства с помощью эвакуатора Town Truck\n";
                Assert::AreEqual(expectedOutput, output.str());
            }
    
    };
    TEST_CLASS(TruckTest) {
    public:
        TEST_METHOD(TestTruck) {
            // Создание объекта 
            Truck tt("Truck","Mers",2010,120);

            // Вызов метода repair
            std::ostringstream output;
            std::streambuf* oldCoutBuffer = std::cout.rdbuf();
            std::cout.rdbuf(output.rdbuf()); // Перенаправление вывода в поток output
            tt.loadCargo();
            std::cout.rdbuf(oldCoutBuffer); // Восстановление вывода в стандартный поток

            // Проверка ожидаемого вывода
            std::string expectedOutput = "Загрузка груза в грузовик Truck Mers\n";
            Assert::AreEqual(expectedOutput, output.str());
        }

        TEST_METHOD(TestTruck2) {
            // Создание объекта
            Truck tt("Truck", "Mers", 2010, 120);

            // Вызов метода repair
            std::ostringstream output;
            std::streambuf* oldCoutBuffer = std::cout.rdbuf();
            std::cout.rdbuf(output.rdbuf()); // Перенаправление вывода в поток output
            tt.unloadCargo();
            std::cout.rdbuf(oldCoutBuffer); // Восстановление вывода в стандартный поток

            // Проверка ожидаемого вывода
            std::string expectedOutput = "Выгрузка груза из грузовика Truck Mers\n";
            Assert::AreEqual(expectedOutput, output.str());
        }
    
    };
    TEST_CLASS(ElectricCarTest) {
         public:
            TEST_METHOD(TestElectricCar) {
                // Создание объекта
                ElectricCar el("Tesla", "X", 2021, 4, 500,"G6",true);

                // Вызов метода repair
                std::ostringstream output;
                std::streambuf* oldCoutBuffer = std::cout.rdbuf();
                std::cout.rdbuf(output.rdbuf()); // Перенаправление вывода в поток output
                el.charge();
                std::cout.rdbuf(oldCoutBuffer); // Восстановление вывода в стандартный поток

                // Проверка ожидаемого вывода
                std::string expectedOutput = "Зарядка электромобиля Tesla X\n";
                Assert::AreEqual(expectedOutput, output.str());
            }
            TEST_METHOD(TestElectricCar2) {
                // Создание объекта
                ElectricCar el("Tesla", "X", 2021, 4, 500, "G6", true);

                // Вызов метода repair
                std::ostringstream output;
                std::streambuf* oldCoutBuffer = std::cout.rdbuf();
                std::cout.rdbuf(output.rdbuf()); // Перенаправление вывода в поток output
                el.eco();
                std::cout.rdbuf(oldCoutBuffer); // Восстановление вывода в стандартный поток

                // Проверка ожидаемого вывода
                std::string expectedOutput = "Включить эконом режим у Tesla X\n";
                Assert::AreEqual(expectedOutput, output.str());
            }
    
    };
    TEST_CLASS(HubridCarTest) {
    public:
        TEST_METHOD(TestHubridCar) {
            // Создание объекта
            HybridCar el("Tesla", "X", 2021, 4, 500,500,"G6");

            // Вызов метода repair
            std::ostringstream output;
            std::streambuf* oldCoutBuffer = std::cout.rdbuf();
            std::cout.rdbuf(output.rdbuf()); // Перенаправление вывода в поток output
            el.refillFuel();
            std::cout.rdbuf(oldCoutBuffer); // Восстановление вывода в стандартный поток

            // Проверка ожидаемого вывода
            std::string expectedOutput = "Заправка гибридного автомтомобиля Tesla X\n";
            Assert::AreEqual(expectedOutput, output.str());
        }
    
    };
    TEST_CLASS(Formula_1Test) {
    public:
        TEST_METHOD(TestFormula_1) {
            // Создание объекта
            Formula_1 f1("Ferrari","GH56",2023,2,250,"H600");

            // Вызов метода repair
            std::ostringstream output;
            std::streambuf* oldCoutBuffer = std::cout.rdbuf();
            std::cout.rdbuf(output.rdbuf()); // Перенаправление вывода в поток output
            f1.accelerates();
            std::cout.rdbuf(oldCoutBuffer); // Восстановление вывода в стандартный поток

            // Проверка ожидаемого вывода
            std::string expectedOutput = "Разгоняется до максимальной скорости Ferrari GH56\n";
            Assert::AreEqual(expectedOutput, output.str());
        }

        TEST_METHOD(TestFormula_1_2) {
            // Создание объекта
            Formula_1 f1("Ferrari", "GH56", 2023, 2, 250, "H600");

            // Вызов метода repair
            std::ostringstream output;
            std::streambuf* oldCoutBuffer = std::cout.rdbuf();
            std::cout.rdbuf(output.rdbuf()); // Перенаправление вывода в поток output
            f1.change();
            std::cout.rdbuf(oldCoutBuffer); // Восстановление вывода в стандартный поток

            // Проверка ожидаемого вывода
            std::string expectedOutput = "Смена покрышек у машины Ferrari GH56\n";
            Assert::AreEqual(expectedOutput, output.str());
        }

    };
    TEST_CLASS(SportCarTest)
    {
    public:

        TEST_METHOD(TestSportCar) {
            // Создание объекта 
            SportCar sport("Ford", "Mustang", 5000, 2015, 4, 200, "V8");

            // Вызов метода repair
            std::ostringstream output;
            std::streambuf* oldCoutBuffer = std::cout.rdbuf();
            std::cout.rdbuf(output.rdbuf()); // Перенаправление вывода в поток output
            sport.stops();
            std::cout.rdbuf(oldCoutBuffer); // Восстановление вывода в стандартный поток

            // Проверка ожидаемого вывода
            std::string expectedOutput = "Машина останавливается Ford Mustang\n";
            Assert::AreEqual(expectedOutput, output.str());
        }

        TEST_METHOD(TestSportCar2) {
            // Создание объекта 
            SportCar sport("Ford", "Mustang", 5000, 2015, 4, 200, "V8");

            // Вызов метода repair
            std::ostringstream output;
            std::streambuf* oldCoutBuffer = std::cout.rdbuf();
            std::cout.rdbuf(output.rdbuf()); // Перенаправление вывода в поток output
            sport.drift();
            std::cout.rdbuf(oldCoutBuffer); // Восстановление вывода в стандартный поток

            // Проверка ожидаемого вывода
            std::string expectedOutput = "Машина дрифтит Ford Mustang\n";
            Assert::AreEqual(expectedOutput, output.str());
        }
    };
}
