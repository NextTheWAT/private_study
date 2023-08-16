using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HelloCSharpWin
{
    public partial class Calculator : Form
    {
        public Calculator()
        {
            InitializeComponent();
        }

        private void HelloLable_Click(object sender, EventArgs e)
        {
            //int number = 10;
            //string operator1 = "+";
            //bool isCorrect = true;

            //int sum = 1 + 2;

            int number1 = 1;
            int number2 = 2;

            int sum = number1 + number2;

            HelloLable.Text = sum.ToString();
        }
    }
}
