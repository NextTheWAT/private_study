namespace HelloCSharpWin
{
    partial class Calculator
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.HelloLable = new System.Windows.Forms.Label();
            this.sum1 = new System.Windows.Forms.TextBox();
            this.sum2 = new System.Windows.Forms.TextBox();
            this.SumNumbers = new System.Windows.Forms.Button();
            this.sumResult = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // HelloLable
            // 
            this.HelloLable.AutoSize = true;
            this.HelloLable.Cursor = System.Windows.Forms.Cursors.Hand;
            this.HelloLable.Location = new System.Drawing.Point(34, 34);
            this.HelloLable.Name = "HelloLable";
            this.HelloLable.Size = new System.Drawing.Size(109, 12);
            this.HelloLable.TabIndex = 0;
            this.HelloLable.Text = "여기를 클릭하세요.";
            this.HelloLable.Click += new System.EventHandler(this.HelloLable_Click);
            // 
            // sum1
            // 
            this.sum1.Location = new System.Drawing.Point(12, 94);
            this.sum1.Name = "sum1";
            this.sum1.Size = new System.Drawing.Size(116, 21);
            this.sum1.TabIndex = 1;
            // 
            // sum2
            // 
            this.sum2.Location = new System.Drawing.Point(175, 94);
            this.sum2.Name = "sum2";
            this.sum2.Size = new System.Drawing.Size(116, 21);
            this.sum2.TabIndex = 2;
            // 
            // SumNumbers
            // 
            this.SumNumbers.Location = new System.Drawing.Point(329, 84);
            this.SumNumbers.Name = "SumNumbers";
            this.SumNumbers.Size = new System.Drawing.Size(76, 39);
            this.SumNumbers.TabIndex = 3;
            this.SumNumbers.Text = "=";
            this.SumNumbers.UseVisualStyleBackColor = true;
            this.SumNumbers.Click += new System.EventHandler(this.SumNumbers_Click);
            // 
            // sumResult
            // 
            this.sumResult.Location = new System.Drawing.Point(441, 94);
            this.sumResult.Name = "sumResult";
            this.sumResult.Size = new System.Drawing.Size(134, 21);
            this.sumResult.TabIndex = 4;
            // 
            // Calculator
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(787, 456);
            this.Controls.Add(this.sumResult);
            this.Controls.Add(this.SumNumbers);
            this.Controls.Add(this.sum2);
            this.Controls.Add(this.sum1);
            this.Controls.Add(this.HelloLable);
            this.Name = "Calculator";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label HelloLable;
        private System.Windows.Forms.TextBox sum1;
        private System.Windows.Forms.TextBox sum2;
        private System.Windows.Forms.Button SumNumbers;
        private System.Windows.Forms.TextBox sumResult;
    }
}

