def direct_complement(number): #Прямой формат
    if number == 0:
        return '0'

    binary = ''
    negative = False

    if number < 0:
        negative = True
        number = abs(number)

    while number > 0:
        binary = str(number % 2) + binary
        number //= 2

    if negative:
        binary = '1' + binary
    else:
        binary = '0' + binary

    return binary
def inverse_complement(number): #Инверсия
    binary = direct_complement(number)
    return inverse_complement_binary(binary)
def inverse_complement_binary(b_number): #Инверсия
    binary = b_number
    if binary[0] == '0':
        complement = binary
        return complement
    else:
        invers = ''
        for bit in binary:
            if bit == '0':
                invers += '1'
            else:
                invers += '0'
        invers = '1' + invers[1:]
        return invers
def twos_complement_alg(binary):

    if binary[0] == '0':
        complement = binary
        return complement

    complement = ''
    i = len(binary) - 1
    while i > 0:
        if binary[i] == '1':
            complement = '0' + complement
        else:
            complement = '1' + complement
            break
        i -= 1
    complement = str(binary[:i]) + complement
    return complement

def twos_complement_binary(b_number): #Дополнительный код
    binary = inverse_complement_binary(b_number)
    return twos_complement_alg(binary)
def twos_complement(number): #Дополнительный код
    binary = inverse_complement(number)
    return twos_complement_alg(binary)
def add_binary(bin1, bin2):
    max_len = max(len(bin1), len(bin2))
    bin1 = bin1.zfill(max_len)
    bin2 = bin2.zfill(max_len)

    result = ''
    carry = 0

    for i in range(max_len - 1, -1, -1):
        total_sum = carry
        total_sum += 1 if bin1[i] == '1' else 0
        total_sum += 1 if bin2[i] == '1' else 0

        result = ('1' if total_sum % 2 == 1 else '0') + result
        carry = 0 if total_sum < 2 else 1

    if carry != 0:
        result = '1' + result

    return '0' + result.lstrip('0') or '0'  # Удаляем ведущие нули и добавляем знаковый бит
def invert(bin_str):
    return ''.join('1' if bit == '0' else '0' for bit in bin_str)
def add_one(bin_str):
    if '0' in bin_str:
        return bin_str.rsplit('0', 1)[0] + '1' + '0' * (len(bin_str) - bin_str.rfind('0') - 1)
    else:
        return '1' + '0' * len(bin_str)
def subtract_binary(bin1, bin2):
    max_len = max(len(bin1), len(bin2))
    bin1 = bin1.zfill(max_len)
    bin2 = bin2.zfill(max_len)

    bin2_inverted = invert(bin2)  # Инвертируем вычитаемое
    bin2_inverted_plus_one = add_one(bin2_inverted)  # Добавляем 1 (дополнение до двух)

    result = add_binary(bin1, bin2_inverted_plus_one)  # Складываем

    # Если результат длиннее изначального уменьшаемого, убираем самый старший бит
    if len(result) > max_len:
        result = result[1:]

    return result[1:].lstrip('0') or '0'
def add (a, b):
    num1 = twos_complement(a)
    num2 = twos_complement(b)
    result = add_binary(num1, num2)
    return result
def substract (a, b):
    num1 = twos_complement(a)
    num2 = twos_complement(b)
    if a > b:
        bit = '0'
    else:
        bit = ('')
    result = subtract_binary(num1, num2)
    return bit + result
def multiply(a, b):
    if a < 0 and b < 0:
        bit = '0'
    elif a < 0 or b < 0:
        bit = ('1')
    else:
        bit = '0'
    a = abs(a)
    b = abs(b)
    num1 = direct_complement(a)
    num2 = direct_complement(b)
    if num1 == '0' or num2 == '0':
        return 0
    if num1 == '01':
        return num2
    elif num2 == '01':
        return num2

    carry = {}
    step = 1

    for i in num2[::-1]:
        if i == '1':
            carry[step] = num1+'0'* (step-1)
            step += 1
        else:
            carry[step] = '0'
            step += 1
    result = '0'
    for j in carry:
        result = add_binary(result, carry.get(j))
    return bit + result[1:]
def divide_binary(dividend, divisor):
    dividend = str(twos_complement(dividend))
    divisor = str(twos_complement(divisor))
    # Убедимся, что делитель не нулевой
    if int(divisor, 2) == 0:
        raise ValueError("Деление на ноль не определено.")

    # Обрезаем ведущие нули с обеих строк
    dividend = dividend.lstrip('0')
    divisor = divisor.lstrip('0')

    # Результат и оставшийся остаток от деления
    quotient = ''
    remainder = 0

    # Выполняем деление, двигаясь по каждому биту делимого
    for digit in dividend:
        # Умножаем предыдущий остаток на 2 и добавляем текущий бит
        remainder = (remainder << 1) | int(digit)

        # Если текущий остаток больше или равен делителю, мы вычитаем делитель из остатка
        if remainder >= int(divisor, 2):
            remainder -= int(divisor, 2)
            quotient += '1'
        else:
            quotient += '0'

    # Формируем строку остатка в двоичном виде
    binary_remainder = bin(remainder).replace('0b', '').rjust(len(divisor), '0')

    # Убираем ведущие нули в частном и остатке
    return quotient.lstrip('0') or '0', binary_remainder
def decimal_to_ieee754(number):
    # Проверка на ноль
    if number == 0.0:
        return '00000000000000000000000000000000'

    # Определение знака
    sign = '1' if number < 0 else '0'

    # Преобразование числа в абсолютное значение
    number = abs(number)

    # Определение экспоненты и нормализация
    exponent = 127
    while number >= 2.0:
        number /= 2.0
        exponent += 1
    while number < 1.0:
        number *= 2.0
        exponent -= 1

    # Преобразование экспоненты в двоичную форму
    exponent_binary = twos_complement(exponent)[1:]

    # Преобразование мантиссы в двоичную форму
    mantissa_binary = ''
    fraction = number - 1.0
    for _ in range(23):
        fraction *= 2.0
        bit = '1' if fraction >= 1.0 else '0'
        mantissa_binary += bit
        if fraction >= 1.0:
            fraction -= 1.0

    # Сборка битов в формате IEEE-754
    ieee754_binary = sign + exponent_binary + mantissa_binary

    return ieee754_binary
def ieee754_addition(number1, number2):
    # Проверка на входные строки
    if len(number1) != 32 or len(number2) != 32:
        raise ValueError("Неверный формат чисел в формате IEEE 754")

    # Получение знаков чисел
    sign1 = int(number1[0])
    sign2 = int(number2[0])

    # Получение экспонент и мантисс чисел
    exponent1 = int(number1[1:9], 2)
    exponent2 = int(number2[1:9], 2)
    mantissa1 = "1" + number1[9:32]
    mantissa2 = "1" + number2[9:32]

    # Приведение мантисс к одной длине
    while len(mantissa1) < len(mantissa2):
        mantissa1 += "0"
    while len(mantissa2) < len(mantissa1):
        mantissa2 += "0"

    # Вычисление новой экспоненты и сдвиг мантисс
    new_exponent, diff = 0, 0
    if exponent1 > exponent2:
        diff = exponent1 - exponent2
        new_exponent = exponent1
        mantissa2 = "0" * diff + mantissa2
    else:
        diff = exponent2 - exponent1
        new_exponent = exponent2
        mantissa1 = "0" * diff + mantissa1

    # Сложение мантисс
    sum_mantissa = ""
    carry = 0
    for i in range(len(mantissa1) - 1, -1, -1):
        bit_sum = int(mantissa1[i]) + int(mantissa2[i]) + carry
        sum_mantissa = str(bit_sum % 2) + sum_mantissa
        carry = bit_sum // 2

    # Обработка переноса при сложении мантисс
    if carry == 1:
        sum_mantissa = "1" + sum_mantissa
        new_exponent += 1

    # Обработка ситуации, когда сумма мантисс превышает 1
    if len(sum_mantissa) > 23:
        sum_mantissa = sum_mantissa[1:24]
        new_exponent += 1

    # Приведение экспоненты к двоичному представлению
    new_exponent = bin(new_exponent)[2:].zfill(8)

    # Формирование результата
    result = str(sign1) + new_exponent + sum_mantissa

    return result
