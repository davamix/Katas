using System;

namespace GreetingKata
{
    public abstract class GreetMessageBase : IGreetMessage{
        public abstract string Message{get;}

        protected string GetSeparator(string name, string _namesToGreet, bool isLast){
            if(string.IsNullOrEmpty(_namesToGreet))
                return string.Empty;
            
            if(isLast)
                return " and ";
            
            return ", ";
        }
        
        public abstract void AddNameToGreet(string name, bool isLast);
        
    }

    public class GreetMessage : GreetMessageBase{
        private string _namesToGreet;
        public override string Message => $"{_namesToGreet}";

        public override void AddNameToGreet(string name, bool isLast){
            var separator = GetSeparator(name, _namesToGreet, isLast);
            _namesToGreet += $"{separator}{name}";
        }
    }

    public class GreetShouttedMessage : GreetMessageBase{
        private string _namesToGreet;
        public override string Message => $"{_namesToGreet}";

        public override void AddNameToGreet(string name, bool isLast){
            var separator = GetSeparator(name, _namesToGreet, isLast);
            _namesToGreet += $"{separator}{name}";
        }
    }
}