# Домашнее задание к занятию «Поведенческие шаблоны: Command, Iterator, Observer, Chain of Responsibility»


### Цель задания

Выполнив это задание, вы закрепите знания и понимание идеи паттернов:

- команда,
- наблюдатель,
- цепочка ответственности.

Цель домашней работы — продемонстрировать способ реализации одной и той же задачи логирования
по-разному в зависимости от применяемого паттерна проектирования.

------

### Чеклист готовности к домашнему заданию

1. Вам понадобятся знания о поведенческих паттернах проектирования, реализации
иерархий классов с полиморфным поведением и знания о работе с файлами в C++.
2. Аккаунт на [GitHub](https://github.com/). [Инструкция по регистрации на GitHub](https://github.com/netology-code/cppm-homeworks/tree/main/common/sign%20up).

------


### Задание 2. Паттерн «Наблюдатель»

Развиваем идею с логированием и пишем класс, за которым смогут наблюдать различные наблюдатели и реагировать на те или иные события.

В задании нужно реализовать несколько классов:

1. Наблюдаемый класс с методами:
- `void warning(const std::string& message) const;`
- `void error(const std::string& message) const;`
- `void fatalError(const std::string& message) const;`

Этот объект должен:

- уметь добавлять не владеющие указатели на наблюдателей,
- оповещать наблюдателей о вызове каждого из методов,
- корректно обрабатывать разрушение объектов-наблюдателей.

2. Далее нужно реализовать небольшую иерархию классов-наблюдателей, реализующих интерфейс:
```
class Observer {
public:
    virtual void onWarning(const std::string& message) {}
    virtual void onError(const std::string& message) {}
    virtual void onFatalError(const std::string& message) {}
};
```

В иерархии классов-наблюдателей нужно реализовать:

- класс для работы с предупреждениями, который будет печатать сообщение в консоль;
- класс для работы с ошибками, который будет печатать сообщение в файл по указанному пути;
- класс для работы с фатальными ошибками, который будет печатать сообщение в консоль и в файл по указанному пути.

------

### Правила приёма работы

Чтобы сдать домашнее задание, прикрепите в личном кабинете ссылку на ваш репозиторий.

### Критерии оценки домашней работы

1. В личном кабинете прикреплена ссылка на репозиторий с кодом для заданий 1, 2 и 3.
2. По ссылке содержится код, который компилируется и при запуске выполняет описанные в задании задачи.
