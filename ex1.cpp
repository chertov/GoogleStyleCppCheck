namespace test
{
    /// doxygen comment
    class CTest
    {
    public: // уже обрабатывается корректно
    int t;  // ошибка
        int t = 1;  // нормально
        if (t == 1)
            // тут будет ошибка, т.к. скобок нет и, соответственно,
            // нет вложенного блока, а отступов уже 2
            std::cout << "Hello, World!" << std::endl;
        else
        {
            // тут ошибки нет, т.к. строка обрабатывается уже внутри блока else
            std::cout << std::endl;
        }
    }
}
