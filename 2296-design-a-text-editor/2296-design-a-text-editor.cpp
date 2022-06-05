class TextEditor {
public:
    
    list<char> _text;
    list<char>::iterator _cursor;
    
    TextEditor() : _cursor{_text.begin()} {
    }
    
    void print_text() {
        cout << "TEXT: ";
        for (char c : _text)
            cout << c;
        cout << endl;
    }
    
    void addText(string text) {
        for (char c : text)
            _cursor = next(_text.insert(_cursor, c));
    }
    
    int deleteText(int k) {
        int del{0};
        while(k--) {
            if (_cursor == _text.begin()) break;
            ++del;
            _cursor = _text.erase(prev(_cursor));
        }
        return del;
    }
    
    string last10() {
        int ct = 10;
        auto it = _cursor;
        while(it != _text.begin() && ct) {
            --ct;
            --it;
        }
        return string(it, _cursor);
    }
    
    string cursorLeft(int k) {
        while(_cursor != _text.begin() && k) {
            --k;
            --_cursor;
        }
        return last10();
    }
    
    string cursorRight(int k) {
        while(_cursor != _text.end() && k) {
            --k;
            ++_cursor;
        }
        return last10();
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */