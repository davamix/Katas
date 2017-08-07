using System;

namespace GreetingKata
{
    public interface IGreetMessage{
        string Message{get;}
        void AddNameToGreet(string name, bool isLast);
    }
}