namespace D2Launcher
{
    partial class MainWindow
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.multi = new System.Windows.Forms.CheckBox();
            this.fullscreen = new System.Windows.Forms.CheckBox();
            this.installDir = new System.Windows.Forms.TextBox();
            this.classicCdKey = new System.Windows.Forms.TextBox();
            this.xpakCdKey = new System.Windows.Forms.TextBox();
            this.launchButton = new System.Windows.Forms.Button();
            this.sound = new System.Windows.Forms.CheckBox();
            this.sleepy = new System.Windows.Forms.CheckBox();
            this.resolutionBox = new System.Windows.Forms.ComboBox();
            this.mapHack = new System.Windows.Forms.CheckBox();
            this.SuspendLayout();
            // 
            // multi
            // 
            this.multi.AutoSize = true;
            this.multi.Checked = true;
            this.multi.CheckState = System.Windows.Forms.CheckState.Checked;
            this.multi.Location = new System.Drawing.Point(87, 117);
            this.multi.Name = "multi";
            this.multi.Size = new System.Drawing.Size(48, 17);
            this.multi.TabIndex = 0;
            this.multi.Text = "Multi";
            this.multi.UseVisualStyleBackColor = true;
            // 
            // fullscreen
            // 
            this.fullscreen.AutoSize = true;
            this.fullscreen.Checked = true;
            this.fullscreen.CheckState = System.Windows.Forms.CheckState.Checked;
            this.fullscreen.Location = new System.Drawing.Point(13, 117);
            this.fullscreen.Name = "fullscreen";
            this.fullscreen.Size = new System.Drawing.Size(74, 17);
            this.fullscreen.TabIndex = 1;
            this.fullscreen.Text = "Fullscreen";
            this.fullscreen.UseVisualStyleBackColor = true;
            this.fullscreen.CheckedChanged += new System.EventHandler(this.fullscreen_CheckedChanged);
            // 
            // installDir
            // 
            this.installDir.Location = new System.Drawing.Point(12, 12);
            this.installDir.Name = "installDir";
            this.installDir.Size = new System.Drawing.Size(242, 20);
            this.installDir.TabIndex = 2;
            // 
            // classicCdKey
            // 
            this.classicCdKey.Location = new System.Drawing.Point(13, 38);
            this.classicCdKey.Name = "classicCdKey";
            this.classicCdKey.Size = new System.Drawing.Size(241, 20);
            this.classicCdKey.TabIndex = 3;
            // 
            // xpakCdKey
            // 
            this.xpakCdKey.Location = new System.Drawing.Point(13, 64);
            this.xpakCdKey.Name = "xpakCdKey";
            this.xpakCdKey.Size = new System.Drawing.Size(241, 20);
            this.xpakCdKey.TabIndex = 4;
            // 
            // launchButton
            // 
            this.launchButton.Location = new System.Drawing.Point(12, 164);
            this.launchButton.Name = "launchButton";
            this.launchButton.Size = new System.Drawing.Size(242, 23);
            this.launchButton.TabIndex = 5;
            this.launchButton.Text = "Launch";
            this.launchButton.UseVisualStyleBackColor = true;
            this.launchButton.Click += new System.EventHandler(this.launchButton_Click);
            // 
            // sound
            // 
            this.sound.AutoSize = true;
            this.sound.Checked = true;
            this.sound.CheckState = System.Windows.Forms.CheckState.Checked;
            this.sound.Location = new System.Drawing.Point(134, 117);
            this.sound.Name = "sound";
            this.sound.Size = new System.Drawing.Size(57, 17);
            this.sound.TabIndex = 6;
            this.sound.Text = "Sound";
            this.sound.UseVisualStyleBackColor = true;
            // 
            // sleepy
            // 
            this.sleepy.AutoSize = true;
            this.sleepy.Checked = true;
            this.sleepy.CheckState = System.Windows.Forms.CheckState.Checked;
            this.sleepy.Location = new System.Drawing.Point(193, 117);
            this.sleepy.Name = "sleepy";
            this.sleepy.Size = new System.Drawing.Size(58, 17);
            this.sleepy.TabIndex = 7;
            this.sleepy.Text = "Sleepy";
            this.sleepy.UseVisualStyleBackColor = true;
            // 
            // resolutionBox
            // 
            this.resolutionBox.FormattingEnabled = true;
            this.resolutionBox.Items.AddRange(new object[] {
            "640x480",
            "768x480",
            "800x600",
            "1024x600",
            "1024x768",
            "1280x768",
            "1280x800",
            "1280x960",
            "1400x1050",
            "1600x1200",
            "1920x1080",
            "1920x1200",
            "1920x1280",
            "2560x1440",
            "2560x1600",
            "3840x2400"});
            this.resolutionBox.Location = new System.Drawing.Point(13, 91);
            this.resolutionBox.Name = "resolutionBox";
            this.resolutionBox.Size = new System.Drawing.Size(241, 21);
            this.resolutionBox.TabIndex = 8;
            this.resolutionBox.SelectedIndexChanged += new System.EventHandler(this.resolutionBox_SelectedIndexChanged);
            // 
            // mapHack
            // 
            this.mapHack.AutoSize = true;
            this.mapHack.Checked = true;
            this.mapHack.CheckState = System.Windows.Forms.CheckState.Checked;
            this.mapHack.Location = new System.Drawing.Point(87, 140);
            this.mapHack.Name = "mapHack";
            this.mapHack.Size = new System.Drawing.Size(71, 17);
            this.mapHack.TabIndex = 9;
            this.mapHack.Text = "Maphack";
            this.mapHack.UseVisualStyleBackColor = true;
            // 
            // MainWindow
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(268, 199);
            this.Controls.Add(this.mapHack);
            this.Controls.Add(this.resolutionBox);
            this.Controls.Add(this.sleepy);
            this.Controls.Add(this.sound);
            this.Controls.Add(this.launchButton);
            this.Controls.Add(this.xpakCdKey);
            this.Controls.Add(this.classicCdKey);
            this.Controls.Add(this.installDir);
            this.Controls.Add(this.fullscreen);
            this.Controls.Add(this.multi);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "MainWindow";
            this.Text = "Shalzuth\'s D2 Launcher";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.CheckBox multi;
        private System.Windows.Forms.CheckBox fullscreen;
        private System.Windows.Forms.TextBox installDir;
        private System.Windows.Forms.TextBox classicCdKey;
        private System.Windows.Forms.TextBox xpakCdKey;
        private System.Windows.Forms.Button launchButton;
        private System.Windows.Forms.CheckBox sound;
        private System.Windows.Forms.CheckBox sleepy;
        private System.Windows.Forms.ComboBox resolutionBox;
        private System.Windows.Forms.CheckBox mapHack;
    }
}

