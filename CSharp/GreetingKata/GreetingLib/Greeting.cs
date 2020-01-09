using System;
using System.Linq;

namespace GreetingKata
{
    public class GreetService{

        private IGreetMessage _greetMessage;
        private IGreetMessage _greetShouttedMessage;

        public GreetService()
        {
            _greetMessage = new GreetMessage();
            _greetShouttedMessage = new GreetShouttedMessage();
        }

        public void JoinNamesToGreet(string[] names){
            if(names == null || names.Length <= 0){
                _greetMessage.AddNameToGreet("my friend", true);
            }else{
                for(var x=0; x<names.Length; x++){
                    if(IsShoutted(names[x])){
                        _greetShouttedMessage.AddNameToGreet(names[x], x == names.Length - 1);
                    }else{
                        _greetMessage.AddNameToGreet(names[x], x == names.Length - 1);
                    }
                    
                }
            }
        }

        public string GetMessage(){
            var msg = string.Empty;

            if(!string.IsNullOrEmpty(_greetMessage.Message) && 
                !string.IsNullOrEmpty(_greetShouttedMessage.Message)){
                
                return $"Hello, {_greetMessage.Message}. AND HELLO {_greetShouttedMessage.Message}!";
            }

            if(string.IsNullOrEmpty(_greetMessage.Message)){
                return $"HELLO {_greetShouttedMessage.Message}!";
            }

            return $"Hello, {_greetMessage.Message}.";
        }

        private bool IsShoutted(string name){
            return name.All(c=>char.IsUpper(c));
        }
    }

    public class Greeting
    {
        private GreetService _service;

        public string Greet(string value = ""){
            if(string.IsNullOrEmpty(value)){
                return Greet(new string[]{});
            }

            return Greet(new[]{value});
        }

        public string Greet(string[] value){
            _service = new GreetService();

            _service.JoinNamesToGreet(value);

            return _service.GetMessage();
        }
    }
}
