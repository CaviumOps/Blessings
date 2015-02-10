
# password dialog

# Based on:
# http://effbot.org/tkinterbook/tkinter-dialog-windows.htm


from Tkinter import *
import tkMessageBox as box
import zlib


def crc32(s):
    return 0xffffffff & zlib.adler32(s)

def makeentry(parent, caption, width=None, **options):
    Label(parent, text=caption).pack(side=LEFT)
    entry = Entry(parent, **options)
    if width:
        entry.config(width=width)
    entry.pack(side=LEFT)
    return entry

class PasswordDialog(Toplevel):

    def __init__(self, parent, pwlabel, pwhash):

        Toplevel.__init__(self, parent)
        self.transient(parent)

        self.parent = parent

        
        self.bind("<Return>", self.verify)

        # Label(top, text=pwlabel).pack()
        top = self
        self.top = top

        self.password = makeentry(
                top, pwlabel, 50, show="*")
        self.password.pack(pady=5)

        self.grab_set()
        self.password.focus_set()

        # self.ok = Button(top, text="OK", command=self.verify)
        # self.ok.pack()

        self.result = False
        self.pwhash = pwhash


    def verify(self, arg):
        # print "arg", arg

        pw = self.password.get()
        if crc32(pw) == self.pwhash:
            self.result = True
            self.close()
        else:
            print pw, crc32(pw), self.pwhash
            box.showerror("Password mismatch", "Password mismatch.")
            self.close()

    def close(self):
        self.withdraw()
        self.update_idletasks()
        self.parent.focus_set()
        self.destroy()

def password_dialog(root, label, crc):
    d = PasswordDialog(root, label, crc)
    root.wait_window(d)
    return d.result

# root = Tk()
# Button(root, text="Hello!", command=password_dialog).pack()
# root.mainloop()

