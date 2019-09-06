#include <iostream>

using namespace std;

int str_length(string str);
string convert_tens(string str);
string check_length(string str);
string convert_1_str_to_num(string str);
string convert_2_str_to_num(string str);
string convert_3_str_to_num(string str);
string convert_4_str_to_num(string str);
string convert_5_str_to_num(string str);


int main(int argc, char const *argv[]) {

  string str = "";

  while (str != "quit") {

    cout << "Please Type 'quit' To Exit The Program\n\n";
    cout << "Please Enter A Number\n";
    cout << " - - > ";
    cin >> str;


    if (str == "quit") {
      cout << "Bye!\n";
      return 0;
    }
    cout << "\nConverting... - - > ** { "<< check_length(str) << " } ** < - - ...Complete." << "\n\n";

  }




  return 0;
}

int str_length(string str) {

  int i = 0;

  while (str[i] != '\0') {
    i++;
  }

  return i;
}

string check_length(string str) {

  string error = "";
  string error_word = "";
  string new_str = "";
  string str_fix_space = "";
  int len = 0;
  int x = 0;

  if (str_length(str) <= 0) {
    return "Error: Invalid Input";
  }

  if (str_length(str) == 1) {
    new_str += convert_1_str_to_num(str);
  } else if (str_length(str) == 2) {
    new_str += convert_2_str_to_num(str);
  } else if (str_length(str) == 3) {
    new_str += convert_3_str_to_num(str);
  } else if (str_length(str) == 4) {
    new_str += convert_4_str_to_num(str);
  } else if (str_length(str) == 5) {
    new_str += convert_5_str_to_num(str);
  } else {
    new_str = "Sorry I Can't Go That High...";
  }

  while (new_str[x] != '\0') {
    if (new_str[x] == ' ') {
      error_word = error;
      error = "";
      if (error_word == "Error") {
        new_str = "There is an error in your input";
        break;
      }
    } else {
      error += new_str[x];
    }
    x++;
  }

  len = str_length(new_str);
  if (new_str[str_length(new_str) - 1] == ' ') {
    for (int i = 0; i < len - 1; i++) {
      str_fix_space += new_str[i];
    }
    new_str = str_fix_space;
  }

  return new_str;
}

string convert_1_str_to_num(string str) {

  if (str == "0") {
    return "zero";
  } else if (str == "1") {
    return "one";
  } else if (str == "2") {
    return "two";
  } else if (str == "3") {
    return "three";
  } else if (str == "4") {
    return "four";
  } else if (str == "5") {
    return "five";
  } else if (str == "6") {
    return "six";
  } else if (str == "7") {
    return "seven";
  } else if (str == "8") {
    return "eight";
  } else if (str == "9") {
    return "nine";
  } else {
    return "Error : Invalid Character";
  }

}

string convert_2_str_to_num(string str) {
  string new_str = "";
  string capture_str = "";

  if (str == "10") {
    return "ten";
  } else if (str == "11") {
    return "eleven";
  } else if (str == "12") {
    return "twelve";
  } else if (str == "13") {
    return "thirteen";
  } else if (str == "14") {
    return "fourteen";
  } else if (str == "15") {
    return "fifteen";
  } else if (str == "16") {
    return "sixteen";
  } else if (str == "17") {
    return "seventeen";
  } else if (str == "18") {
    return "eightteen";
  } else if (str == "19") {
    return "nineteen";
  }

  capture_str = str[0];
  if (capture_str != "0") {
    new_str += convert_tens(capture_str);
    new_str += " ";
  }
  capture_str = str[1];
  if (capture_str != "0") new_str += convert_1_str_to_num(capture_str);

  return new_str;
}

string convert_tens(string str) {

  if (str == "2") {
    return "twenty";
  } else if (str == "3") {
    return "thirty";
  } else if (str == "4") {
    return "fourty";
  } else if (str == "5") {
    return "fifty";
  } else if (str == "6") {
    return "sixty";
  } else if (str == "7") {
    return "seventy";
  } else if (str == "8") {
    return "eighty";
  } else if (str == "9") {
    return "ninety";
  } else {
    return "Error : Invalid Character";
  }

}

string convert_3_str_to_num(string str) {
  string new_str = "";
  string capture_str = "";

  capture_str = str[0];
  if (capture_str != "0") {
    new_str += convert_1_str_to_num(capture_str);
    new_str += " hundred ";
  }
  capture_str = str[1];
  if (capture_str == "1") {
    capture_str += str[2];
    new_str += convert_2_str_to_num(capture_str);
    return new_str;
  } else if (capture_str != "0" && capture_str != "1") {
    new_str += convert_tens(capture_str);
  }
  capture_str = str[2];
  if (capture_str != "0") {
    // new_str += " ";
    new_str += convert_1_str_to_num(capture_str);
  }

  return new_str;
}

string convert_4_str_to_num(string str) {
  string new_str = "";
  string capture_str = "";

  capture_str = str[0];
  if (capture_str != "0") new_str += convert_1_str_to_num(capture_str);
  new_str += " thousand ";
  capture_str = str[1];
  capture_str += str[2];
  capture_str += str[3];
  new_str += convert_3_str_to_num(capture_str);

  return new_str;
}

string convert_5_str_to_num(string str) {
  string new_str = "";
  string capture_str = "";

  capture_str = str[0];

  if (capture_str != "0") {
    capture_str += str[1];
    new_str += convert_2_str_to_num(capture_str);
    new_str += " thousand ";
  }

  capture_str = str[2];
  capture_str += str[3];
  capture_str += str[4];

  new_str += convert_3_str_to_num(capture_str);


  return new_str;
}
