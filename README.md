<h2> Contest 3 </h2>

Коди на всі задачі знаходяться в папці `src`. 

Розв'язки в файлах не факт що співпадають з поясненими тут. Якщо вам цікаво як написати будь-який з описаних тут розв'язків - напишіть мені.

**A**

1. Легко помітити, що відповідь - це (сумма від `1` до `b`) - (сума від `1` до `(a - 1)`). Отде, `ans = b * (b + 1) / 2 - a * (a + 1) / 2`
2. Порахувати циклом

**B**

Рахуємо всі попарні різниці - `b[i] #= a[i + 1] - a[i]`. Знаходимо min, max в отриманому масиві і рахуємо відповідь.

**C**

Порахуємо, яка сумарна кількість мотузок (`f(m)`) буде якщо вибрати довжину `m` (для усіх). Ми маємо 

`f(m) #= sum_i l[i] // m`

Наша ціль - знайти таке максимальне $m$, що `f(m) >= k`. 

Ми можемо зазначити, що `f(m) < f(m - 1)` для усіх `m`, а значить шукати відповідь бінарним пошуком.

https://uk.wikipedia.org/wiki/%D0%94%D0%B2%D1%96%D0%B9%D0%BA%D0%BE%D0%B2%D0%B8%D0%B9_%D0%BF%D0%BE%D1%88%D1%83%D0%BA

**D**

Будемо зберігати два стека. `mn` - для мінімумів (`mn[i] = min(st[1], st[2], ... , st[i])`) та `st` - для реальних значень.

Реалізуємо операції 

1. `add(v)`  -> `st.add(v)`. Як змінився мінімум? `mn[st.size] = min(mn[st.size - 1], st[st.size])` - він або такий, яким був, або новий елемент

2. `pop` - просто `mn.pop(); st.pop()`

3. `min` - просто `mn[mn.size]` - це за визначенням мінімум на всьому стеку.

**E**

Псевдокод:

```
n = int(input())
f[0] = 1
f[1] = 1
for i in range(2, n + 1):
    f[i] = f[i - 1] + f[i - 2]
print(f[n])
```

Важливо лонг лонги!!!

**F**

Можна або перевірити всі числа на відрізку на простоту за $O(\sqrt n)$. Буде розібрана на некст лекції.

Або можна написати решето Ератосфена. 

https://uk.wikipedia.org/wiki/%D0%A0%D0%B5%D1%88%D0%B5%D1%82%D0%BE_%D0%95%D1%80%D0%B0%D1%82%D0%BE%D1%81%D1%84%D0%B5%D0%BD%D0%B0

**G**

Класична задача - можемо зробити так:

Псевдокод:

```
n = input()
for (int d = 2; d * d <= n; d++) {
    if (n % d == 0) {
        ans += 2
        if (n == d * d) {
            ans -= 1
        }
    }
}
output(n)
```

Знаходимо всі пари дільників - якщо число повний квадрат, то рахуємо пару лише один раз. $O(\sqrt n)$.

**H**

Задача легко вирішується такими структурами даних: дерево відрізків, SQRT-декомпозиція, дерево фенвіка. Будуть розібрані в майбутьньому :)
