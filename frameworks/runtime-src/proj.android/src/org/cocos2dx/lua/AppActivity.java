/****************************************************************************
Copyright (c) 2008-2010 Ricardo Quesada
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2011      Zynga Inc.
Copyright (c) 2013-2014 Chukong Technologies Inc.
 
http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package org.cocos2dx.lua;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

import org.cocos2dx.lib.Cocos2dxActivity;
import org.cocos2dx.lib.Cocos2dxGLSurfaceView;

import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.text.ClipboardManager;
import android.util.Log;
import android.webkit.DownloadListener;
import android.webkit.WebView;
import android.widget.FrameLayout;
import android.widget.LinearLayout;
import android.widget.Button;
import android.app.ProgressDialog;
import android.content.Context;
import android.content.Intent;
import android.webkit.WebViewClient;
import android.view.View.OnClickListener;
import android.graphics.Color;
import android.view.KeyEvent;
import android.view.View;
import android.view.View.OnKeyListener;
import android.view.WindowManager.LayoutParams;
import android.graphics.Bitmap;
import org.cocos2dx.lib.Cocos2dxLuaJavaBridge;

public class AppActivity extends Cocos2dxActivity {
	private static AppActivity instance = null;
	WebView m_webView;
	FrameLayout m_webLayout;
	LinearLayout topLayout;
	Button backButton;
	int webViewLuaFunc;
	int copyResCallbackFunc;
	
	private static final int DO_PASTE = 0;
	private static final int DO_URL = 1;
	private static final int COPY_RES = 2;
	private static final int SET_LOCAL_PUSH = 3;
	
	private static Handler handler = new Handler() {
		@Override
		public void handleMessage(Message msg) {
			Log.e("EvilCard", "Handler msg.what: "+msg.what);
			if (msg.what == DO_PASTE) {
				AppActivity aa = AppActivity.getInstance();
				ClipboardManager cmb = (ClipboardManager)aa.getSystemService(Context.CLIPBOARD_SERVICE);
				cmb.setText((String.valueOf(msg.obj)).trim());
			} else if (msg.what == DO_URL) {
				AppActivity aa = AppActivity.getInstance();
				aa.initWebView(String.valueOf(msg.obj));
				aa.setWebViewLuaFunc(msg.arg1);
			} else if (msg.what == COPY_RES) {
				AppActivity aa = AppActivity.getInstance();
//				aa.setCopyResCallbackFunc(msg.arg1);
				final int callback = msg.arg1;
				aa.copyAssetsByDir("res/patch", String.valueOf(msg.obj));
				aa.callbackCopyRes(callback);
			} else if (msg.what == SET_LOCAL_PUSH) {
				AppActivity aa = AppActivity.getInstance();
				
				/*
				NotificationManager nm = (NotificationManager) aa.getSystemService(Context.NOTIFICATION_SERVICE);
				int nIcon = R.drawable.icon;
				CharSequence nTitle = "决战王者通知";
				long when = System.currentTimeMillis();
				//1.实例化一个通知，指定图标、概要、时间
				Notification n = new Notification(nIcon, nTitle, when);
				//2.指定通知的标题、内容和intent
				Intent intent = new Intent(aa, AppActivity.class);
				PendingIntent pi= PendingIntent.getActivity(aa, 0, intent, 0);
				String title = "通知标题";
				String content = String.valueOf(msg.obj);
				n.setLatestEventInfo(aa, title, content, pi);
				//3.指定声音
				n.defaults = Notification.DEFAULT_SOUND;
				//4.发送通知
				nm.notify(1, n);
				*/
				
//				PushService.pushTitle = new String("决战王者");
//				PushService.pushDetail = new String(String.valueOf(msg.obj));
//				Log.e("EvilCard", "pushTitle: "+PushService.pushTitle);
				
				Intent pushIntent = new Intent("com.evil.game.action.PushService");
				pushIntent.putExtra("title", "决战王者");
				pushIntent.putExtra("detail", String.valueOf(msg.obj));
				pushIntent.putExtra("time", msg.arg1);
                aa.startService(pushIntent);  
			}
			super.handleMessage(msg);
		}
	};

	public Cocos2dxGLSurfaceView onCreateView() {
		Cocos2dxGLSurfaceView glSurfaceView = new Cocos2dxGLSurfaceView(this);
		// kelton : fix bug about ClippingNode
		glSurfaceView.setEGLConfigChooser(5, 6, 5, 0, 16, 8);
		return glSurfaceView;
	}

	protected void onCreate(Bundle saveInstanceState) {
		super.onCreate(saveInstanceState);
		Log.e("EvilCard", "AppActivity onCreate");
		instance = this;
		m_webLayout = new FrameLayout(this);
		webViewLuaFunc = 0;
		addContentView(m_webLayout, new LayoutParams(LayoutParams.MATCH_PARENT,LayoutParams.MATCH_PARENT));
	}

	public void setWebViewLuaFunc(final int luaFunc) {
		this.webViewLuaFunc = luaFunc;
	}
	
	public void setCopyResCallbackFunc(final int luaFunc) {
		this.copyResCallbackFunc = luaFunc;
	}
	
	public void callbackCopyRes(final int luaFunc) {
		if (0 != luaFunc) {
			Cocos2dxLuaJavaBridge.callLuaFunctionWithString(luaFunc, "done");
			Cocos2dxLuaJavaBridge.releaseLuaFunction(luaFunc);
		}
	}
	
	public void copyAssetsByDir(String dir, String dstPath) {
//		Log.e("EvilCard", "AppActivity copyAssetsByDir start");
		String[] files;
		try {
			files = this.getResources().getAssets().list(dir);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return;
		}
		File dst = new File(dstPath);
		if (!dst.exists()) {
			if (!dst.mkdirs()) {
				Log.e("EvilCard", "AppActivity copyAssets cannot create directory");
			}
		}
		
		for (int i = 0; i < files.length; i++) {
			String fileName = files[i];
			Log.e("EvilCard", "AppActivity copyAssets fileName[" + fileName + "]");
			if (!fileName.contains(".")) {
				this.copyAssetsByDir(dir + "/" + fileName, dstPath);
				continue;
			}
			
			Log.e("EvilCard", "AppActivity copyAssets dir[" + dir + "] file[" + fileName + "]");
			File outFile = new File(dstPath, fileName);
			if (outFile.exists()) {
				outFile.delete();
			}
			InputStream in = null;
			OutputStream out = null;
			try {
				if (0 != dir.length()) {
					in = this.getResources().getAssets().open(dir + "/" + fileName);
				} else {
					in = this.getResources().getAssets().open(fileName);
				}
				out = new FileOutputStream(outFile);
				byte[] buf = new byte[1024];
				int len;
				while ((len = in.read(buf)) > 0) {
					out.write(buf, 0, len);
				}
				in.close();
				out.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
		}
//		Log.e("EvilCard", "AppActivity copyAssetsByDir end");
	}
	
	public static void copyRes(final String dstPath, final int luaFunc) {
		Log.e("EvilCard", "copyRes: "+dstPath);
		Message msg = new Message();
		msg.what = COPY_RES;
		msg.obj = dstPath;
		msg.arg1 = luaFunc;
		handler.sendMessage(msg);
	}
	
	public static void setLocalPush(final int sec, final int min, final int hours, final int days, final int startHour, final int endHour, final String message) {
		Message msg = new Message();
		msg.what = SET_LOCAL_PUSH;
		msg.obj = message;
		msg.arg1 = (sec + min*60 + hours*60*60 + days*60*60*24) * 1000;
		Log.e("EvilCard", "setLocalPush message: "+message+" time: "+msg.arg1);
		handler.sendMessage(msg);
	}

	public static void openURL(final String url, final int luaFunc) {
		Log.e("EvilCard", "openUrl: "+url);
		Message msg = new Message();
		msg.what = DO_URL;
		msg.obj = url;
		msg.arg1 = luaFunc;
		handler.sendMessage(msg);
	}

	public static void textToPasteboard(final String text) {
		Log.e("EvilCard", "textToPasteboard: "+text);
		Message msg = new Message();
		msg.what = DO_PASTE;
		msg.obj = text;
		handler.sendMessage(msg);
	}
	
	@Override
	public void onDestroy() {
		super.onDestroy();
		System.exit(0);
	}
	

	public static void exitGame() {
		AppActivity aa = AppActivity.getInstance();
		aa.finish();
	}

	public static AppActivity getInstance() {
		return instance;
	}

	public void initWebView(String urlString) {
		final String url = urlString;
		Log.e("EvilCard", "AppActivity openURL step 1");
		this.runOnUiThread(new Runnable() {//在主线程里添加别的控件
			public void run() {   
				//初始化webView
				m_webView = new WebView(instance);
				m_webView.setDownloadListener(new webViewDownloadListener());
				//设置webView能够执行javascript脚本
				m_webView.getSettings().setJavaScriptEnabled(true);
				//设置可以支持缩放
				m_webView.getSettings().setSupportZoom(true);//设置出现缩放工具
				m_webView.getSettings().setBuiltInZoomControls(true);
				//载入URL
				m_webView.loadUrl(url);
				//使页面获得焦点
				m_webView.requestFocus();
				//如果页面中链接，如果希望点击链接继续在当前browser中响应
				m_webView.setWebViewClient(new WebViewClient(){ 
					public ProgressDialog loadingView = null;
					public boolean shouldOverrideUrlLoading(WebView view, String url) {   
						if(url.indexOf("tel:")<0){
							view.loadUrl(url); 
						}
						Log.e("EvilCard", "shouldOverrideUrlLoading");
						return true;       
					}

					public void onPageStarted(WebView view, String url, Bitmap favicon) {
						Log.e("EvilCard", "onPageStarted");
						if (null == loadingView) {
						loadingView = ProgressDialog.show(AppActivity.this, "提示", "努力加载中...", true);
						}
					}

					public void onPageFinished(WebView view, String url) {
						Log.e("EvilCard", "onPageFinished");
						if (null != loadingView) {
							loadingView.dismiss();
							loadingView = null;
						}
					}
				});
				m_webView.setOnKeyListener(new OnKeyListener() {
					@Override
					public boolean onKey(View arg0, int arg1, KeyEvent arg2) {
						// TODO Auto-generated method stub
						if (arg2.getAction() == KeyEvent.ACTION_DOWN) {
							if (arg1 == KeyEvent.KEYCODE_BACK) {
								Log.e("EvilCard", "onKeyBack");
//								m_webView.goBack();
								removeWebView();
								return true; // means has handled
							}
						}
						return false;
					}
				});
				/*背景图*/                
				//                m_imageView = new ImageView(instance);
				//                m_imageView.setImageResource(R.drawable.lobbybg);
				//                m_imageView.setScaleType(ImageView.ScaleType.FIT_XY);
				/*初始化线性布局 里面加按钮和webView*/
				topLayout = new LinearLayout(instance);      
				topLayout.setOrientation(LinearLayout.VERTICAL);
				/*初始化返回按钮*/
				backButton = new Button(instance);
				//                backButton.setBackgroundResource(R.drawable.backbutton);
				backButton.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT));
				backButton.setText("关闭");
				backButton.setTextColor(Color.argb(255, 0, 0, 0));
				backButton.setTextSize(14);                
				backButton.setOnClickListener(new OnClickListener() {
					@Override
					public void onClick(View arg0) {
						// TODO Auto-generated method stub
						Log.e("EvilCard", "removeWebView");
						removeWebView();
					}
				});
				//把image加到主布局里
				//                m_webLayout.addView(m_imageView);
				//把webView加入到线性布局 
				topLayout.addView(backButton);
				topLayout.addView(m_webView);
				//再把线性布局加入到主布局
				m_webLayout.addView(topLayout);
			}
		});
	}
	
	private class webViewDownloadListener implements DownloadListener {

		@Override
		public void onDownloadStart(String url, String userAgent, String contentDisposition,
				String mimetype, long contentLength) {
			// TODO Auto-generated method stub
			Uri uri = Uri.parse(url);
			Log.i("EvilCard", "download url " + uri);
			Intent intent =  new Intent(Intent.ACTION_VIEW, uri);
			startActivity(intent);
		}
		
	}

	//移除webView  把刚才加的所有控件都删掉
	public void removeWebView() {              
		m_webLayout.removeView(topLayout);
		topLayout.destroyDrawingCache();

		topLayout.removeView(m_webView);
		m_webView.destroy();

		topLayout.removeView(backButton);
		backButton.destroyDrawingCache();

		Log.e("EvilCard", "AppActivity removeWebView:"+webViewLuaFunc);
		
		if (0 == webViewLuaFunc) {
			return;
		}
		Cocos2dxLuaJavaBridge.callLuaFunctionWithString(webViewLuaFunc, "back");
		Cocos2dxLuaJavaBridge.releaseLuaFunction(webViewLuaFunc);
		webViewLuaFunc = 0;
	}
}
