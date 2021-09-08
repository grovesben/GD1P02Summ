#include "DequeManager.h"


CDequeManager::CDequeManager()
{
    m_ProgramRunning = true;
    m_iInput = 0;
    CDeque* deque = new CDeque;
    m_pDeque = deque;
    m_iDequeuedData = 0;
    m_iPeekedData = 0;
}

CDequeManager::~CDequeManager()
{
}

int CDequeManager::Run()
{
    while (m_ProgramRunning) 
    {
        std::cout << "1. Enqueue_Front  \n";
        std::cout << "2. Enqueue_Back   \n";
        std::cout << "3. Dequeue_Front  \n";
        std::cout << "4. Dequeue_Back   \n";
        std::cout << "5. Peek_Front     \n";
        std::cout << "6. Peek_Back      \n";
        std::cout << "7. IsEmpty        \n";
        std::cout << "8. Exit           \n";

        std::cout << "Choose an option. \n";

        Menu();
    }

    return 0;
}

void CDequeManager::Menu()
{
    m_iInput = _getch();
    while (m_iInput < 49 || m_iInput > 56) {
        if (m_iInput < 49 || m_iInput > 56) {
            std::cout << "Please choose from the menu.\n";
            m_iInput = _getch();
        }
    } 

    switch (m_iInput) {
    case 49: // ascii "1"
    {
        system("CLS");
        m_iInput = Input();
        system("CLS");
        m_pDeque->Enqueue_Front(m_iInput);
        m_pDeque->Display();

       break;
    }
    case 50: // ascii "2"
    {
        system("CLS");
        m_iInput = Input();
        system("CLS");
        m_pDeque->Enqueue_Back(m_iInput);
        m_pDeque->Display();
        break;
    }
    case 51: // ascii "3"
    {
        system("CLS");
        if (m_pDeque->IsEmpty())
        {
            std::cout << "Deque is empty.\n\n";
        }
        else
        {
            m_pDeque->Dequeue_Front(m_iDequeuedData);
            std::cout << "Dequeued data: " << m_iDequeuedData << std::endl;
            m_pDeque->Display();
        }
        break;
    }
    case 52: // ascii "4"
    {
        system("CLS");
        if (m_pDeque->IsEmpty())
        {
            std::cout << "Deque is empty.\n\n";
        }
        else
        {
            m_pDeque->Dequeue_Back(m_iDequeuedData);
            std::cout << "Dequeued data: " << m_iDequeuedData << std::endl;
            m_pDeque->Display();
        }
        break;
    }
    case 53: // ascii "5"
    {
        system("CLS");
        if (m_pDeque->IsEmpty())
        {
            std::cout << "Deque is empty.\n\n";
        }
        else
        {
            m_pDeque->Peek_Front(m_iPeekedData);
            std::cout << "Peeked data: " << m_iPeekedData << std::endl;
            m_pDeque->Display();
        }
        break;
    }
    case 54: // ascii "6"
    {
        system("CLS");
        if (m_pDeque->IsEmpty())
        {
            std::cout << "Deque is empty.\n\n";
        }
        else
        {
            m_pDeque->Peek_Back(m_iPeekedData);
            std::cout << "Peeked data: " << m_iPeekedData << std::endl;
            m_pDeque->Display();
        }
        break;
        break;
    }
    case 55: // ascii "7"
    {
        system("CLS");
        if (m_pDeque->IsEmpty())
        {
            std::cout << "True\n";
        }
        else
        {
            std::cout << "False\n";
        }
        m_pDeque->Display();
        break;
    }
    case 56: // ascii "8"
    {
        m_ProgramRunning = false;
        break;
    }
    }
}

int CDequeManager::Input()
{
    while (1)
    {
        
        std::cout << "Please input an integer: ";
        
        if (std::cin >> m_iInput)
        {
            return m_iInput;
        }
        else
        {
            system("CLS");
            std::cout << "Invalid input.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
